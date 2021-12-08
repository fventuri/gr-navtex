/* -*- c++ -*- */
/*
 * Copyright 2021 Franco Venturi.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_NAVTEX_NAVTEX_DECODER_IMPL_H
#define INCLUDED_NAVTEX_NAVTEX_DECODER_IMPL_H

#include <gnuradio/navtex/navtex_decoder.h>
#include <navtex_rx.h>

#include <cstdio>

namespace gr {
namespace navtex {

template <class T>
class navtex_decoder_impl : public navtex_decoder<T>
{
private:
    FILE* rawfile;
    navtex_rx* nv;

public:
    navtex_decoder_impl(int sampling_rate, const std::string filename, bool reverse);
    ~navtex_decoder_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace navtex
} // namespace gr

#endif /* INCLUDED_NAVTEX_NAVTEX_DECODER_IMPL_H */
