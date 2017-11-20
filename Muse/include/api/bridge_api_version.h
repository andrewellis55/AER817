// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libmuse_version.djinni

#pragma once

#include <cstdint>
#include <string>

namespace interaxon { namespace bridge {

/**
 * Library version interface.
 *
 * Describes the version of LibMuse.
 */
class ApiVersion {
public:
    virtual ~ApiVersion() {}

    /**
     * Returns a monotonically increasing version number.
     *
     * This number is guaranteed to increase from release to release.
     * Currently it is equivalent to:
     *
     *     get_major() * 1000000 + get_minor() * 10000 + get_patch() * 100 + get_api()
     *
     * So for major = 5, minor = 1, patch = 3, api = 2, it would be 5010302.
     */
    virtual int64_t get_monotonic() = 0;

    /**
     * Major release.
     *
     * This number is incremented on a major release of new functionality.
     * \return The major version.
     */
    virtual int64_t get_major() = 0;

    /**
     * Minor release.
     *
     * This number is incremented when minor changes are made that are backwards
     * compatible.
     * \return The minor version.
     */
    virtual int64_t get_minor() = 0;

    /**
     * Patch release.
     *
     * This number is incremented when backwards-compatible bugfixes are made.
     * \return The patch version.
     */
    virtual int64_t get_patch() = 0;

    /**
     * API
     *
     * This number is incremented when changes are introduced to the API that are
     * not backwards compatible.
     * \return The API version.
     */
    virtual int64_t get_api() = 0;

    /**
     * String representation of the version.
     *
     * This is a string like "x.y.z API Version j" where x is get_major(),
     * y is get_minor(), z is get_patch() and j is get_api(). The format may
     * change from release to release.  In particular, don't make assumptions
     * about it or try to parse it.  Use the other API calls on this interface
     * to get the numerical versions.
     * \return The version string.
     */
    virtual std::string get_string() = 0;
};

} }  // namespace interaxon::bridge
