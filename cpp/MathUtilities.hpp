#ifndef MATH_UTILITIES_H
#define MATH_UTILITIES_H

#include <vector>
#include <map>
#include <cmath>

#include <iostream>

using namespace std;

namespace MathUtilities {
//----------------------------------------------------------------------------------------------------
    /* Mean */
//----------------------------------------------------------------------------------------------------
    template <typename T>
    T ComputeMean(T value[], int size) {
        T result = 0;

        for (int i = 0; i < size; i++) {
            result += value[i];
        }
        return result/size;
    }

    template <typename T>
    T ComputeMean(vector<T> value) {
        T *array = &value[0];
        return ComputeMean(array, value.size());
    }


    /*
     * Intput: map    -> std::map
     *         member -> member of the struct that is in the map,
     *             	     it is used only to get the type that shall be returned
     *         offset -> offset to the member of the struct,
     *         		     can be retrived by used offsetof (stddef.h)
     */
    template <typename M, typename T>
    T ComputeMean(M map,T member, int offset) {
        typename M::iterator it;
        char *baseAdress;
        T *b;
        T mean = 0;
        for(it = map.begin(); it != map.end(); ++it) {
            baseAdress = (char *) (&it->second);
            b = (T *)(baseAdress+offset);
            mean += *b;
        }
        return mean/map.size();
    }

    template <typename M, typename T>
    T ComputeMean(M map){
        typename M::iterator it;
        //typedef M::mapped_type T;

        T mean = 0;

        for(it = map.begin(); it != map.end(); ++it) {
            mean += it->second;
        }
        return mean/map.size();
    }




//----------------------------------------------------------------------------------------------------
    /* Mean Deviation */
//----------------------------------------------------------------------------------------------------

    template <typename T>
    T ComputeMeanDeviation(T value[], int size) {
        T mean = ComputeMean(value, size);
        T meanDeviation = 0;

        for (int i = 0; i < size; i++) {
            meanDeviation += AbsoluteValue(value[i] - mean);
        }
        return meanDeviation/size;
    }

    template <typename T>
    T ComputeMeanDeviation(vector<T> value) {
        T *array = &value[0];
        return ComputeMeanDeviation(array, value.size());
    }


    /*
     * Intput: map    -> std::map
     *         member -> member of the struct that is in the map,
     *                   it is used only to get the type that shall be returned
     *         offset -> offset to the member of the struct,
     *                   can be retrived by used offsetof (stddef.h)
     */
    template <typename M, typename T>
    T ComputeMeanDeviation(M map,T member, int offset) {
        typename M::iterator it;
        char *baseAdress;
        T *b;
        T mean = ComputeMean(map, member, offset);
        T meanDeviation = 0;

        for(it = map.begin(); it != map.end(); ++it) {
            baseAdress = (char *) (&it->second);
            b = (T *)(baseAdress+offset);
            meanDeviation += AbsoluteValue(*b - mean);
        }
        return meanDeviation/map.size();
    }



//----------------------------------------------------------------------------------------------------
    /* Standard Deviation */
//----------------------------------------------------------------------------------------------------
    template <typename T>
    T ComputeStandardDeviation(T value[], int size) {
        T result = 0;
        T mean = ComputeMean(value, size);
        for (int i = 0; i < size; i++) {
            result += pow( (value[i] - mean), 2);
        }
        result /= size;
        return sqrt(result);
    }

    template <typename T>
    T ComputeStandardDeviation(vector<T> value) {
        T *array = &value[0];
        return ComputeStandardDeviation(array, value.size());
    }

    /*
     * Intput: map    -> std::map
     *         member -> member of the struct that is in the map,
     *                   it is used only to get the type that shall be returned
     *         offset -> offset to the member of the struct,
     *                   can be retrived by used offsetof (stddef.h)
     */
    template <typename M, typename T>
    T ComputeStandardDeviation(M map,T member, int offset) {
        typename M::iterator it;
        char *baseAdress;
        T *b;
        T mean = ComputeMean(map, member, offset);
        T standardDeviation = 0;

        for(it = map.begin(); it != map.end(); ++it) {
            baseAdress = (char *) (&it->second);
            b = (T *)(baseAdress+offset);
            standardDeviation += pow( (*b - mean), 2);
        }
        return standardDeviation/map.size();
    }

    template <typename T>
    T AbsoluteValue(T value) {
        T result = pow(value,2);
        return sqrt(result);
    }


};//namespace


#endif
