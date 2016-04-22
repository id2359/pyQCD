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
 */


#include "comms.hpp"


namespace pyQCD
{
  Communicator::Communicator() : initialized_(false)
  { }

  void Communicator::init(MPI_Comm& comm)
  {
    comm_ = &comm;
    MPI_Comm_size(comm, &size_);
    MPI_Comm_rank(comm, &rank_);
    initialized_ = true;
  }

  Communicator& Communicator::instance()
  {
    static Communicator ret;
    return ret;
  }
}