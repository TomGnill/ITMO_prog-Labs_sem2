#pragma once
#include <iterator>

//#2
template <typename dia_zone, typename element>
bool any_of(const dia_zone begin, const dia_zone end, bool(&func)(element))
{
    for (auto it = begin; it != end; it++) {
        if (func(*it))
            return true;
    }
    return  false;
}
//#5
template <typename dia_zone, typename element>
bool is_sorted(dia_zone begin, dia_zone end, bool (&func)(element, element))
{
    dia_zone prev_element = begin;
    for (auto it = begin; it != end; it++)
    {
        if (!func(*prev_element, *it))
            return false;
        prev_element = it;
    }
    return true;
}
//#9
 template <typename dia_zone, typename element>
 bool is_palendrome(const dia_zone begin, const dia_zone end, bool (&func)(element))
 {

     for (auto it_left = begin, it_right = std::prev(end); it_left != end && it_right != begin; it_left = std::next(it_left), it_right = std::prev(it_right))
     {
         if (func(*it_left) && func(*it_right))
         {
             return true;
         }
         return false;
     }
 }