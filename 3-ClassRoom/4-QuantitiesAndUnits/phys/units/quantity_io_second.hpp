/**
 * \file quantity_io_second.hpp
 *
 * \brief   second, fundamental dimension.
 * \author  Martin Moene
 * \date    7 September 2013
 * \since   1.0
 *
 * Copyright 2013 Universiteit Leiden. All rights reserved.
 * This code is provided as-is, with no warrantee of correctness.
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef PHYS_UNITS_QUANTITY_IO_SECOND_HPP_INCLUDED
#define PHYS_UNITS_QUANTITY_IO_SECOND_HPP_INCLUDED

#include "phys/units/quantity_io.hpp"

namespace phys { namespace units {

/// time_interval_d

template<>
struct unit_info< time_interval_d >
{
   static bool        single() { return true; }
   static std::string name()   { return "second"; }
   static std::string symbol() { return "s"; }
};

namespace literals {

QUANTITY_DEFINE_SCALING_LITERALS( min , time_interval_d, 60 )
QUANTITY_DEFINE_SCALING_LITERALS( hour, time_interval_d, 60 * 60 )
QUANTITY_DEFINE_SCALING_LITERALS( day , time_interval_d, 24 * 60 * 60 )

}

}} // namespace phys::units

#endif // PHYS_UNITS_QUANTITY_IO_SECOND_HPP_INCLUDED

/*
 * end of file
 */
