/*
 * This file is part of pyQCD.
 *
 * pyQCD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * pyQCD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *
 * Created by Matt Spraggs on 10/02/16.
 *
 *
 * Tests for the Random class.
 */
#define CATCH_CONFIG_MAIN

#include <utils/random.hpp>

#include "helpers.hpp"


TEST_CASE("Testing RNG")
{

  Compare<double> comp(1.0e-3, 1.0e-3);

  unsigned num_trials = 100000;
  double mean = 0.0;

  for (unsigned i = 0; i < num_trials; ++i) {
    auto random = pyQCD::rng().generate_real<double>(0.0, 1.0);
    mean += random;

    REQUIRE((random >= 0.0 and random < 1.0));
  }
  mean /= num_trials;

  REQUIRE(comp(mean, 0.5));
}