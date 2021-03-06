/*
 * Copyright 2016-2017 Internet Corporation for Assigned Names and Numbers.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, you can obtain one at https://mozilla.org/MPL/2.0/.
 */

/*
 * Developed by Sinodun IT (www.sinodun.com)
 */

#ifndef PACKETSTATISTICS_HPP
#define PACKETSTATISTICS_HPP

#include <cstdint>

/**
 * \typedef PacketStatistics
 * \brief Statistics on packet collection.
 *
 * \struct PacketStatistics_s
 * \brief A structure holding statistics.
 *
 * All of the counts below are from since the program run started.
 */
using PacketStatistics = struct PacketStatistics_s
{
    /**
     * \brief count of packets received.
     */
    uint64_t raw_packet_count;

    /**
     * \brief count of malformed DNS packets received.
     */
    uint64_t malformed_packet_count;

    /**
     * \brief count of DNS packets received out of time order.
     */
    uint64_t out_of_order_packet_count;

    /**
     * \brief count of unhandled packets received.
     */
    uint64_t unhandled_packet_count;

    /**
     * \brief count of total query/response pairs output.
     */
    uint64_t qr_pair_count;

    /**
     * \brief count of queries with no matching response.
     */
    uint64_t query_without_response_count;

    /**
     * \brief count of responses with no matching query.
     */
    uint64_t response_without_query_count;

    /**
     * \brief count from PCAP of packets received.
     */
    uint64_t pcap_recv_count;

    /**
     * \brief count from PCAP of packets dropped by kernel.
     */
    uint64_t pcap_drop_count;

    /**
     * \brief count from PCAP of packets dropped by interface.
     */
    uint64_t pcap_ifdrop_count;

    /**
     * \brief count of raw PCAP packets dropped by output.
     */
    uint64_t output_raw_pcap_drop_count;

    /**
     * \brief count of ignored PCAP packets dropped by output.
     */
    uint64_t output_ignored_pcap_drop_count;

    /**
     * \brief count of CBOR items dropped by output.
     */
    uint64_t output_cbor_drop_count;

    /**
     * \brief Dump the stats to the stream provided
     *
     * \param os output stream.
     */
    void dump_stats(std::ostream& os) {
        os << "\nSTATISTICS:\n"
           << "  Total Packets processed                  : " << raw_packet_count << "\n"
           << "  Matched DNS query/response pairs (C-DNS) : " << qr_pair_count << "\n"
           << "  Unmatched DNS queries            (C-DNS) : " << query_without_response_count << "\n"
           << "  Unmatched DNS responses          (C-DNS) : " << response_without_query_count << "\n"
           << "  Malformed DNS packets                    : " << malformed_packet_count << "\n"
           << "  Non-DNS packets                          : " << unhandled_packet_count  << "\n"
           << "  Out-of-order DNS query/responses         : " << out_of_order_packet_count << "\n"
           << "  Dropped C-DNS items (overload)           : " << output_cbor_drop_count << "\n"
           << "  Dropped raw PCAP packets (overload)      : " << output_raw_pcap_drop_count << "\n"
           << "  Dropped non-DNS packets (overload)       : " << output_ignored_pcap_drop_count << "\n\n";
    }
};

#endif
