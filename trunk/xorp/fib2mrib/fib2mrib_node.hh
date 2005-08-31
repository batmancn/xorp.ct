// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2005 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

// $XORP: xorp/fib2mrib/fib2mrib_node.hh,v 1.15 2005/03/25 02:53:21 pavlin Exp $

#ifndef __FIB2MRIB_FIB2MRIB_NODE_HH__
#define __FIB2MRIB_FIB2MRIB_NODE_HH__


//
// Fib2mrib node definition.
//

#include <map>

#include "libxorp/service.hh"
#include "libxorp/status_codes.h"

#include "libfeaclient/ifmgr_xrl_mirror.hh"

#include "policy/backend/policytags.hh"
#include "policy/backend/policy_filters.hh"

class EventLoop;

/**
 * @short A Fib2mrib helper class.
 * 
 * This class is used to store a routing entry.
 */
class Fib2mribRoute {
public:
    /**
     * Constructor for a given IPv4 route.
     * 
     * @param network the network address prefix this route applies to.
     * @param nexthop the address of the next-hop router for this route.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param metric the routing metric for this route.
     * @param admin_distance the administratively defined distance for this
     * route.
     * @param protocol_origin the name of the protocol that originated this
     * route.
     * @param xorp_route true if this route was installed by XORP.
     */
    Fib2mribRoute(const IPv4Net& network, const IPv4& nexthop,
		  const string& ifname, const string& vifname,
		  uint32_t metric, uint32_t admin_distance,
		  const string& protocol_origin, bool xorp_route)
	: _network(network), _nexthop(nexthop),
	  _ifname(ifname), _vifname(vifname),
	  _metric(metric), _admin_distance(admin_distance),
	  _protocol_origin(protocol_origin), _xorp_route(xorp_route),
	  _route_type(IDLE_ROUTE), _is_ignored(false),
	  _is_filtered(false) {}

    /**
     * Constructor for a given IPv6 route.
     * 
     * @param network the network address prefix this route applies to.
     * @param nexthop the address of the next-hop router for this route.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param metric the routing metric for this route.
     * @param admin_distance the administratively defined distance for this
     * route.
     * @param protocol_origin the name of the protocol that originated this
     * route.
     * @param xorp_route true if this route was installed by XORP.
     */
    Fib2mribRoute(const IPv6Net& network, const IPv6& nexthop,
		  const string& ifname, const string& vifname,
		  uint32_t metric, uint32_t admin_distance,
		  const string& protocol_origin, bool xorp_route)
	: _network(network), _nexthop(nexthop),
	  _ifname(ifname), _vifname(vifname),
	  _metric(metric), _admin_distance(admin_distance),
	  _protocol_origin(protocol_origin), _xorp_route(xorp_route),
	  _route_type(IDLE_ROUTE), _is_ignored(false),
	  _is_filtered(false) {}

    /**
     * Equality Operator
     * 
     * @param other the right-hand operand to compare against.
     * @return true if the left-hand operand is numerically same as the
     * right-hand operand.
     */
    bool operator==(const Fib2mribRoute& other) const {
	return ((_network == other.network())
		&& (_nexthop == other.nexthop())
		&& (_ifname == other.ifname())
		&& (_vifname == other.vifname())
		&& (_metric == other.metric())
		&& (_route_type == other._route_type)
		&& (_policytags == other._policytags));
    }

    /**
     * Test if this is an IPv4 route.
     * 
     * @return true if this is an IPv4 route, otherwise false.
     */
    bool is_ipv4() const { return _network.is_ipv4(); }

    /**
     * Test if this is an IPv6 route.
     * 
     * @return true if this is an IPv6 route, otherwise false.
     */
    bool is_ipv6() const { return _network.is_ipv6(); }

    /**
     * Get the network address prefix this route applies to.
     * 
     * @return the network address prefix this route appies to.
     */
    const IPvXNet& network() const { return _network; }

    /**
     * Get the address of the next-hop router for this route.
     * 
     * @return the address of the next-hop router for this route.
     */
    const IPvX& nexthop() const { return _nexthop; }

    /**
     * Set the address of the next-hop router for this route.
     *
     * @param v the address of the next-hop router for this route.
     */
    void set_nexthop(const IPvX& v) { _nexthop = v; }

    /**
     * Get the name of the physical interface toward the destination.
     * 
     * @return the name of the physical interface toward the destination.
     */
    const string& ifname() const { return _ifname; }

    /**
     * Set the name of the physical interface toward the destination.
     *
     * @param v the name of the physical interface toward the destination.
     */
    void set_ifname(const string& v) { _ifname = v; }

    /**
     * Get the name of the virtual interface toward the destination.
     * 
     * @return the name of the virtual interface toward the destination.
     */
    const string& vifname() const { return _vifname; }

    /**
     * Set the name of the virtual interface toward the destination.
     *
     * @param v the name of the virtual interface toward the destination.
     */
    void set_vifname(const string& v) { _vifname = v; }

    /**
     * Get the the administratively defined distance for this route.
     * 
     * @return the administratively defined distance for this route.
     */
    uint32_t admin_distance() const { return _admin_distance; }

    /**
     * Get the metric distance for this route.
     * 
     * @return the metric distance for this route.
     */
    uint32_t metric() const { return _metric; }

    /**
     * Get the name of the protocol that originated this route.
     * 
     * @return the name of the protocol that originated this route.
     */
    const string& protocol_origin() const { return _protocol_origin; }

    /**
     * Test if this route was installed by XORP.
     * 
     * @return true if this route was installed by XORP.
     */
    bool xorp_route() const { return _xorp_route; }

    /**
     * Test if this is a route to add.
     * 
     * @return true if this is a route to add, otherwise false.
     */
    bool is_add_route() const { return (_route_type == ADD_ROUTE); }

    /**
     * Test if this is a replacement route.
     * 
     * @return true if this is a replacement route, otherwise false.
     */
    bool is_replace_route() const { return (_route_type == REPLACE_ROUTE); }

    /**
     * Test if this is a route to delete.
     * 
     * @return true if this is a route to delete, otherwise false.
     */
    bool is_delete_route() const { return (_route_type == DELETE_ROUTE); }

    /**
     * Set the type of this route to "a route to add".
     */
    void set_add_route() { _route_type = ADD_ROUTE; }

    /**
     * Set the type of this route to "a replacement route".
     */
    void set_replace_route() { _route_type = REPLACE_ROUTE; }

    /**
     * Set the type of this route to "a route to delete".
     */
    void set_delete_route() { _route_type = DELETE_ROUTE; }

    /**
     * Test if the route is interface-specific (e.g., if the interface
     * is explicitly specified).
     * 
     * @return true if the route is interface-specific, otherwise false.
     */
    bool is_interface_route() const { return ! (_ifname.empty()
						&& _vifname.empty()); }

    /**
     * Check whether the route entry is valid.
     * 
     * @param error_msg the error message (if error).
     * @return true if the route entry is valid, otherwise false.
     */
    bool is_valid_entry(string& error_msg) const;

    /**
     * Test if the route is to be ignored.
     * 
     * This method is used only for internal purpose when passing the route
     * around.
     * 
     * @return true if the route is to be ignored, otherwise false.
     */
    bool is_ignored() const { return _is_ignored; }

    /**
     * Set whether the route is to be ignored.
     * 
     * This method is used only for internal purpose when passing the route
     * around.
     * 
     * @param v true if the route is to be ignored, otherwise false.
     */
    void set_ignored(bool v) { _is_ignored = v; }

    /**
     * @return policy-tags for this route.
     */
    const PolicyTags& policytags() const { return _policytags; }
    
    /**
     * Set policy-tags for route.
     *
     * @param tags the new policy-tags for this route.
     */
    void set_policytags(const PolicyTags& tags) { _policytags = tags; }

    /**
     * @return whether route has been rejected by policy filter.
     */
    bool is_filtered() const { return _is_filtered; }

    /**
     * Sets whether the route is to be considered filtered [rejected by the
     * policy filter].
     *
     * @param v true if the route should be considered rejected.
     */
    void set_filtered(bool v) { _is_filtered = v; }


private:
    IPvXNet	_network;
    IPvX	_nexthop;
    string	_ifname;
    string	_vifname;
    uint32_t	_metric;
    uint32_t	_admin_distance;
    string	_protocol_origin;
    bool	_xorp_route;
    enum RouteType { IDLE_ROUTE, ADD_ROUTE, REPLACE_ROUTE, DELETE_ROUTE };
    RouteType	_route_type;
    bool	_is_ignored;	// True if the route is to be ignored
    bool	_is_filtered;	// True if rejected by policy filter
    PolicyTags	_policytags;
};


/**
 * @short The Fib2mrib node class.
 * 
 * There should be one node per Fib2mrib instance.
 */
class Fib2mribNode : public IfMgrHintObserver,
		     public ServiceBase,
		     public ServiceChangeObserverBase {
public:
    /**
     * Constructor for a given event loop.
     * 
     * @param eventloop the event loop to use.
     */
    Fib2mribNode(EventLoop& eventloop);

    /**
     * Destructor
     */
    virtual ~Fib2mribNode();

    /**
     * Get the event loop this node is added to.
     * 
     * @return the event loop this node is added to.
     */
    EventLoop&	eventloop()	{ return _eventloop; }

    /**
     * Get the protocol name.
     * 
     * @return a string with the protocol name.
     */
    const string& protocol_name() const { return _protocol_name; }

    /**
     * Startup the node operation.
     *
     * @return true on success, false on failure.
     */
    bool	startup();

    /**
     * Shutdown the node operation.
     *
     * @return true on success, false on failure.
     */
    bool	shutdown();

    /**
     * Get the node status (see @ref ProcessStatus).
     * 
     * @param reason_msg return-by-reference string that contains
     * human-readable information about the status.
     * @return the node status (see @ref ProcessStatus).
     */
    ProcessStatus	node_status(string& reason_msg);

    /**
     * Test if the node processing is done.
     * 
     * @return true if the node processing is done, otherwise false.
     */
    bool	is_done() const { return (_node_status == PROC_DONE); }

    /**
     * Add an IPv4 route.
     *
     * @param network the network address prefix this route applies to.
     * @param nexthop the address of the next-hop router for this route.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param metric the routing metric for this route.
     * @param admin_distance the administratively defined distance for this
     * route.
     * @param protocol_origin the name of the protocol that originated this
     * route.
     * @param xorp_route true if this route was installed by XORP.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int add_route4(const IPv4Net& network, const IPv4& nexthop,
		   const string& ifname, const string& vifname,
		   uint32_t metric, uint32_t admin_distance,
		   const string& protocol_origin, bool xorp_route,
		   string& error_msg);

    /**
     * Add an IPv6 route.
     *
     * @param network the network address prefix this route applies to.
     * @param nexthop the address of the next-hop router for this route.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param metric the routing metric for this route.
     * @param admin_distance the administratively defined distance for this
     * route.
     * @param protocol_origin the name of the protocol that originated this
     * route.
     * @param xorp_route true if this route was installed by XORP.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int add_route6(const IPv6Net& network, const IPv6& nexthop,
		   const string& ifname, const string& vifname,
		   uint32_t metric, uint32_t admin_distance,
		   const string& protocol_origin, bool xorp_route,
		   string& error_msg);

    /**
     * Replace an IPv4 route.
     *
     * @param network the network address prefix this route applies to.
     * @param nexthop the address of the next-hop router for this route.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param metric the routing metric for this route.
     * @param admin_distance the administratively defined distance for this
     * route.
     * @param protocol_origin the name of the protocol that originated this
     * route.
     * @param xorp_route true if this route was installed by XORP.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int replace_route4(const IPv4Net& network, const IPv4& nexthop,
		       const string& ifname, const string& vifname,
		       uint32_t metric, uint32_t admin_distance,
		       const string& protocol_origin, bool xorp_route,
		       string& error_msg);

    /**
     * Replace an IPv6 route.
     *
     * @param network the network address prefix this route applies to.
     * @param nexthop the address of the next-hop router for this route.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param metric the routing metric for this route.
     * @param admin_distance the administratively defined distance for this
     * route.
     * @param protocol_origin the name of the protocol that originated this
     * route.
     * @param xorp_route true if this route was installed by XORP.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int replace_route6(const IPv6Net& network, const IPv6& nexthop,
		       const string& ifname, const string& vifname,
		       uint32_t metric, uint32_t admin_distance,
		       const string& protocol_origin, bool xorp_route,
		       string& error_msg);

    /**
     * Delete an IPv4 route.
     *
     * @param network the network address prefix this route applies to.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int delete_route4(const IPv4Net& network, const string& ifname,
		      const string& vifname, string& error_msg);

    /**
     * Delete an IPv6 route.
     *
     * @param network the network address prefix this route applies to.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int delete_route6(const IPv6Net& network, const string& ifname,
		      const string& vifname, string& error_msg);

    //
    // Debug-related methods
    //
    
    /**
     * Test if trace log is enabled.
     * 
     * This method is used to test whether to output trace log debug messges.
     * 
     * @return true if trace log is enabled, otherwise false.
     */
    bool	is_log_trace() const { return (_is_log_trace); }
    
    /**
     * Enable/disable trace log.
     * 
     * This method is used to enable/disable trace log debug messages output.
     * 
     * @param is_enabled if true, trace log is enabled, otherwise is disabled.
     */
    void	set_log_trace(bool is_enabled) { _is_log_trace = is_enabled; }

    /**
     * Configure a policy filter.
     *
     * Will throw an exception on error.
     *
     * Export filter is not supported by fib2mrib routes.
     *
     * @param filter identifier of filter to configure.
     * @param conf configuration of the filter.
     */
    void configure_filter(const uint32_t& filter, const string& conf);

    /**
     * Reset a policy filter.
     *
     * @param filter identifier of filter to reset.
     */
    void reset_filter(const uint32_t& filter);

    /**
     * Push all the routes through the policy filters for re-filtering.
     */
    void push_routes();


protected:
    //
    // IfMgrHintObserver methods
    //
    void tree_complete();
    void updates_made();

    void incr_startup_requests_n();
    void decr_startup_requests_n();
    void incr_shutdown_requests_n();
    void decr_shutdown_requests_n();
    void update_status();

private:
    /**
     * A method invoked when the status of a service changes.
     * 
     * @param service the service whose status has changed.
     * @param old_status the old status.
     * @param new_status the new status.
     */
    void status_change(ServiceBase*  service,
		       ServiceStatus old_status,
		       ServiceStatus new_status);

    /**
     * Get a reference to the service base of the interface manager.
     * 
     * This is a pure virtual function, and it must be implemented
     * by the communication-wrapper class that inherits this base class.
     *
     * @return a reference to the service base of the interface manager.
     */
    virtual const ServiceBase* ifmgr_mirror_service_base() const = 0;

    /**
     * Get a reference to the interface manager tree.
     * 
     * This is a pure virtual function, and it must be implemented
     * by the communication-wrapper class that inherits this base class.
     *
     * @return a reference to the interface manager tree.
     */
    virtual const IfMgrIfTree&	ifmgr_iftree() const = 0;

    /**
     * Initiate registration with the FEA.
     * 
     * This is a pure virtual function, and it must be implemented
     * by the communication-wrapper class that inherits this base class.
     */
    virtual void fea_register_startup() = 0;

    /**
     * Initiate de-registration with the FEA.
     * 
     * This is a pure virtual function, and it must be implemented
     * by the communication-wrapper class that inherits this base class.
     */
    virtual void fea_register_shutdown() = 0;

    /**
     * Initiate registration with the RIB.
     * 
     * This is a pure virtual function, and it must be implemented
     * by the communication-wrapper class that inherits this base class.
     */
    virtual void rib_register_startup() = 0;

    /**
     * Initiate de-registration with the RIB.
     * 
     * This is a pure virtual function, and it must be implemented
     * by the communication-wrapper class that inherits this base class.
     */
    virtual void rib_register_shutdown() = 0;

    /**
     * Add an IPvX route.
     *
     * @param fib2mrib_route the route to add.
     * @see Fib2mribRoute
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int add_route(const Fib2mribRoute& fib2mrib_route, string& error_msg);

    /**
     * Replace a Fib2mrib IPvX route.
     *
     * @param fib2mrib_route the replacement route.
     * @see Fib2mribRoute
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int replace_route(const Fib2mribRoute& fib2mrib_route, string& error_msg);

    /**
     * Delete a Fib2mrib IPvX route.
     *
     * @param fib2mrib_route the route to delete.
     * @see Fib2mribRoute
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int delete_route(const Fib2mribRoute& fib2mrib_route, string& error_msg);

    /**
     * Inform the RIB about a route change.
     *
     * This is a pure virtual function, and it must be implemented
     * by the communication-wrapper class that inherits this base class.
     *
     * @param fib2mrib_route the route with the information about the change.
     */
    virtual void inform_rib_route_change(const Fib2mribRoute& fib2mrib_route) = 0;

    /**
     * Cancel a pending request to inform the RIB about a route change.
     *
     * This is a pure virtual function, and it must be implemented
     * by the communication-wrapper class that inherits this base class.
     *
     * @param fib2mrib_route the route with the request that would be canceled.
     */
    virtual void cancel_rib_route_change(const Fib2mribRoute& fib2mrib_route) = 0;

    /**
     * Update a route received from the FEA.
     * 
     * This method is needed as a work-around of FEA-related problems
     * with the routes the FEA sends to interested parties such as FIB2MRIB.
     * A route is updated with interface-related information or next-hop
     * address.
     * 
     * The routes received from the FEA for the directly-connected subnets
     * may not contain next-hop information and network interface information.
     * If the route is for a directly-connected subnet, and if it is missing
     * that information, then add the interface and next-hop router
     * information.
     * Furthermore, on startup, the routes received from the FEA may
     * contain interface-related information, but later updates of those
     * routes may be missing this information. This may create a mismatch,
     * therefore all routes are updated (if possible) to contain
     * interface-related information.
     * 
     * @param iftree the tree with the interface state to update the route.
     * @param route the route to update.
     * @return true if the route was updated, otherwise false.
     */
    bool update_route(const IfMgrIfTree& iftree, Fib2mribRoute& route);

    /**
     * Do policy filtering on a route.
     *
     * @param route route to filter.
     * @return true if route was accepted by policy filter, false otherwise.
     */
    bool do_filtering(Fib2mribRoute& route);
    
    /**
     * Inform the RIB about a route.
     *
     * @param r route which should be updated in the RIB.
     */
    void inform_rib(const Fib2mribRoute& r);

    /**
     * Set the node status.
     *
     * @param v the new node status.
     */
    void set_node_status(ProcessStatus v) { _node_status = v; }

    EventLoop&		_eventloop;		// The event loop
    ProcessStatus	_node_status;		// The node/process status
    const string	_protocol_name;		// The protocol name

    //
    // The routes are stored in a multimap, because we allow more than one
    // route for same subnet destination, but with different interface/vif
    // name.
    // E.g., in case of IPv6 we may have the same (link-local) subnet
    // address pre interface.
    //
    multimap<IPvXNet, Fib2mribRoute>	_fib2mrib_routes;

    //
    // Status-related state
    //
    size_t		_startup_requests_n;
    size_t		_shutdown_requests_n;

    //
    // A local copy with the interface state information
    //
    IfMgrIfTree		_iftree;

    //
    // Debug and test-related state
    //
    bool	_is_log_trace;		// If true, enable XLOG_TRACE()

    PolicyFilters	_policy_filters;	// Only one instance of this!
};

#endif // __FIB2MRIB_FIB2MRIB_NODE_HH__
