// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from museinfo.djinni

#pragma once

#include <functional>

namespace interaxon { namespace bridge {

/**
 * \if IOS_ONLY
 * \file
 * \endif
 * The model identifier of the headbands.  The model is laser printed on the
 *  inside of the left pod of the headband as either "MU-01" or "MU-02".
 */
enum class MuseModel : int {
    /** First model of Muse, Muse 2014 */
    MU_01,
    /** Muse 2016 with Bluetooth Low Energy support. */
    MU_02,
};

} }  // namespace interaxon::bridge

namespace std {

template <>
struct hash<::interaxon::bridge::MuseModel> {
    size_t operator()(::interaxon::bridge::MuseModel type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
