from colour_vector cimport ColourVector
from layout cimport Layout


cdef extern from "types.hpp":
    cdef cppclass LatticeColourVector:
        LatticeColourVector() except +
        LatticeColourVector(const Layout&, const ColourVector) except +
        unsigned int volume()
        unsigned int num_dims()