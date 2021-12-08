/* -*- c++ -*- */
/*
 * Copyright 2021 Franco Venturi.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_NAVTEX_NAVTEX_DECODER_H
#define INCLUDED_NAVTEX_NAVTEX_DECODER_H

#include <gnuradio/navtex/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace navtex {

/*!
 * \brief <+description of block+>
 * \ingroup navtex
 *
 */
template <class T>
class NAVTEX_API navtex_decoder : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<navtex_decoder<T>> sptr;

    /*!
     * \brief Make a new instance of the navtex decoder, and return a shared pointer to it.
     * \param sampling_rate sample rate (Hz)
     * \param filename raw file name for character by character output
     * \param reverse reverse mark and space (for LSB instead of USB)
     */
    static sptr make(int sampling_rate, const std::string filename = "", bool reverse = false);
};

typedef navtex_decoder<std::int16_t> navtex_decoder_s;
typedef navtex_decoder<float> navtex_decoder_f;
} // namespace navtex
} // namespace gr

#endif /* INCLUDED_NAVTEX_NAVTEX_DECODER_H */
