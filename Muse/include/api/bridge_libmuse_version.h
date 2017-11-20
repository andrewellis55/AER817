// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libmuse_version.djinni

#pragma once

#include <memory>

namespace interaxon { namespace bridge {

class ApiVersion;

/** The version of the LibMuse library. */
class LibmuseVersion {
public:
    virtual ~LibmuseVersion() {}

    /**
     * Returns the LibMuse API version.
     * \return the LibMuse API version.
     */
    static std::shared_ptr<ApiVersion> instance();
};

} }  // namespace interaxon::bridge
