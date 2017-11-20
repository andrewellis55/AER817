// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from muse_file.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <string>

namespace interaxon { namespace bridge {

class MuseConfiguration;
class MuseDataPacket;
class MuseFile;
class MuseVersion;
enum class TimestampMode;
struct AnnotationData;
struct ComputingDeviceConfiguration;
struct DspData;
struct MuseArtifactPacket;

/**
 * This class manages saving Muse packets and other data into a file,
 * which can later be read and replayed by MusePlayer. Google Protobuf is used
 * to store the information. For better control, data is not written to the file
 * immediately, but stored in a buffer instead. The buffer then can be flushed
 * to a file or discarded.<br>
 *
 * Note that upon creation of a \classlink{MuseFileWriter}, an Annotation and the 
 * ComputingDeviceConfiguration are automatically written out to the file. The annotation 
 * contains the app's name and version and libmuse version. If app's name and version 
 * can not be determined, they will be empty strings. The ComputingDeviceConfiguration 
 * contains hardware information for the computing device. If any information
 * fields can not be determined, they will be empty strings. 
 *
 * <B>Threading:</B> It is thread safe, so you can call write()/get()/flush()/discard()
 * operations from different threads. <br>
 * \if WINDOWS_ONLY
 * However, make sure you do not call these methods from the main UI thread. Please use
 * an async task instead to avoid crashes.
 * \endif
 * \warning If you don't call flush() method, messages will be
 * accumulated in memory and eventually you will get memory overflow error.
 * It's library client responsibility to call flush() or discardBufferedPackets() and to
 * clean the memory. You can use helper methods to get how many messages are
 * currently stored in the buffer and how much memory is used.
 *
 * \sa MusePlayer: http://developer.choosemuse.com/research-tools/museplayer
 */
class MuseFileWriter {
public:
    virtual ~MuseFileWriter() {}

    /**
     * Returns an instance of file writer. Automatically opens a file. <br>
     * \return an instance of the file writer.
     */
    static std::shared_ptr<MuseFileWriter> get_file_writer(const std::shared_ptr<MuseFile> & file);

    /**
     * Opens a file if it exists or creates a new one.
     * If file already exists, all new messages will be appended at the end.
     * Use this method if you explicitly closed file and want to open it again.
     * Calls \functionlink{MuseFile,open,open}
     * \return \c false if the file could not be opened for any reason. \c true otherwise.
     */
    virtual bool open() = 0;

    /**
     * Closes the file. Calls \functionlink{MuseFile,close,close}
     *
     * You don't have to call close explicitly unless you want to close file
     * immediately. close is called automatically, when the file writer object
     * is destroyed.
     * \return \c false if the file could not be closed for any reason. \c true otherwise.
     */
    virtual bool close() = 0;

    /** Removes all saved messages from the memory. */
    virtual void discard_buffered_packets() = 0;

    /**
     * Flashes saved messages to the disk. Calls \functionlink{MuseFile,write,write}
     * \return \c false if can not write to file for any reason. \c true otherwise.
     */
    virtual bool flush() = 0;

    /**
     * Returns number of saved messages
     * \return the number of saved messages.
     */
    virtual int32_t get_bufferred_messages_count() = 0;

    /**
     * Returns the size of saved messages in bytes.
     * \return the size of the saved messages in bytes.
     */
    virtual int32_t get_buffered_messages_size() = 0;

    /**
     * Adds \classlink{MuseArtifactPacket} to the buffer.
     * \param id  The id of the device generating the packet.
     * This is arbitrary and is used to differentiate data from
     * multiple devices in a single file.
     * \param packet The artifact packet to add.
     */
    virtual void add_artifact_packet(int32_t id, const MuseArtifactPacket & packet) = 0;

    /**
     * Adds \classlink{MuseDataPacket}
     * to the buffer. All current packets are supported.
     * \param id  The id of the device generating the packet.
     * This is arbitrary and is used to differentiate data from
     * multiple devices in a single file.
     * \param packet The data packet to add.
     */
    virtual void add_data_packet(int32_t id, const std::shared_ptr<MuseDataPacket> & packet) = 0;

    /**
     * Adds an annotation string to the buffer. It may be useful if you want to
     * log specific events. This is a simplified version of
     * \inlinelink{addAnnotation(),IXNMuseFileWriter::addAnnotation:,add_annotation()}.
     * Use this method if you want to add one string to protobuf. Use
     * \inlinelink{addAnnotation(),IXNMuseFileWriter::addAnnotation:,add_annotation()}
     *  for more advanced options.
     * This function does nothing if annotation is empty.
     * \param id  The id of the device generating the packet.
     * This is arbitrary and is used to differentiate data from
     * multiple devices in a single file.
     * \param annotation The annotation string to add.
     */
    virtual void add_annotation_string(int32_t id, const std::string & annotation) = 0;

    /**
     * Adds annotation data structure to the buffer. Similar to
     * \inlinelink{addAnnotationString(),IXNMuseFileWriter::addAnnotationString:,add_annotation_string()},
     * but this method allows you to extra fields.
     * Empty fields in annotation struct won't be added to protobuf. If
     * annotation.data field is empty, method returns immediately.
     * \param id  The id of the device generating the annotation.
     * This is arbitrary and is used to differentiate data from
     * multiple devices in a single file.
     * \param annotation The annotation data to add.
     */
    virtual void add_annotation(int32_t id, const AnnotationData & annotation) = 0;

    /**
     * Adds \classlink{MuseConfiguration} to the buffer.
     * \param id  The id of the device saving the configuration.
     * This is arbitrary and is used to differentiate data from
     * multiple devices in a single file.
     * \param configuration The configuration data to add.
     */
    virtual void add_configuration(int32_t id, const std::shared_ptr<MuseConfiguration> & configuration) = 0;

    /**
     * Adds \classlink{MuseVersion} to the buffer.
     * \param id  The id of the device saving the version.
     * This is arbitrary and is used to differentiate data from
     * multiple devices in a single file.
     * \param version The version data to add.
     */
    virtual void add_version(int32_t id, const std::shared_ptr<MuseVersion> & version) = 0;

    /**
     * Adds information about the running device to the buffer.
     * \param id  The id of the device saving the configuration.
     * This is arbitrary and is used to differentiate data from
     * multiple devices in a single file.
     * \param configuration The device configuration data to add.
     */
    virtual void add_computing_device_configuration(int32_t id, const ComputingDeviceConfiguration & configuration) = 0;

    /**
     * With this method you can save your custom data.
     * Checkout protobuf schema for details: http://developer.choosemuse.com/file-formats/muse
     * \param id  The id of the device saving the data.
     * This is arbitrary and is used to differentiate data from
     * multiple devices in a single file.
     * \param dsp The data to store.
     */
    virtual void add_dsp(int32_t id, const DspData & dsp) = 0;

    /**
     * Set the timestamp mode.
     *
     * By default, the mode is \enumlink{TimestampMode,LEGACY,IXNTimestampModeLegacy}
     * \param mode The timestamp mode to set.
     */
    virtual void set_timestamp_mode(TimestampMode mode) = 0;

    /**
     * Set the timestamp for the next message to be written.
     *
     * This only does anything in explicit timestamp mode. In explicit mode,
     * the timestamp set by set_timestamp applies to the next message and all
     * subsequent messages. If set_timestamp is not called, then the timestamp
     * is 0.
     *
     * In all other modes, calling set_timestamp causes an assert failure -- the
     * app crashes in debug mode, and it is a noop in release mode.
     *
     * The timestamp is in microseconds since some epoch (usually Jan 1, 1970).
     * \param timestamp The time to use for the timestamp in microseconds.
     */
    virtual void set_timestamp(int64_t timestamp) = 0;
};

} }  // namespace interaxon::bridge
