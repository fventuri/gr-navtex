/* -*- c++ -*- */
/*
 * Copyright 2021 Franco Venturi.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "navtex_decoder_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace navtex {

template <class T>
typename navtex_decoder<T>::sptr navtex_decoder<T>::make(int sampling_rate,
                                                         const std::string filename,
                                                         bool reverse)
{
    return gnuradio::make_block_sptr<navtex_decoder_impl<T>>(sampling_rate, filename, reverse);
}


/*
 * The private constructor
 */
template <class T>
navtex_decoder_impl<T>::navtex_decoder_impl(int sampling_rate, const std::string filename, bool reverse)
    : gr::sync_block("navtex_decoder",
                     gr::io_signature::make(1, 1, sizeof(T)),
                     gr::io_signature::make(0, 0, 0))
{
    if (filename.empty() || filename == "-") {
        rawfile = stdout;
    } else {
        rawfile = fopen(filename.c_str(), "w");
    }
    // disable buffering on raw file
    setvbuf(rawfile, nullptr, _IONBF, 0);
    nv = new navtex_rx(sampling_rate, false, reverse, rawfile); 
}

/*
 * Our virtual destructor.
 */
template <class T>
navtex_decoder_impl<T>::~navtex_decoder_impl()
{
    delete nv;
    nv = nullptr;
    fclose(rawfile);
    if (rawfile == stdout)
        setvbuf(rawfile, nullptr, _IOLBF, 0);
    rawfile = nullptr;
}

template <class T>
int navtex_decoder_impl<T>::work(int noutput_items,
                                 gr_vector_const_void_star& input_items,
                                 gr_vector_void_star& output_items)
{
    auto in = static_cast<const T*>(input_items[0]);
    nv->process_data(in, noutput_items);
    return noutput_items;
}

template class navtex_decoder<std::int16_t>;
template class navtex_decoder<float>;
} /* namespace navtex */
} /* namespace gr */
