/*
 * Copyright (c) 2001-2003 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP$"

#include "ripng_xif.hh"

bool
XrlRipngV0p1Client::send_add_rip_address(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const AddRipAddressCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/add_rip_address");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_add_rip_address, cb));
}


/* Unmarshall add_rip_address */
void
XrlRipngV0p1Client::unmarshall_add_rip_address(
	const XrlError&	e,
	XrlArgs*	a,
	AddRipAddressCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_remove_rip_address(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const RemoveRipAddressCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/remove_rip_address");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_remove_rip_address, cb));
}


/* Unmarshall remove_rip_address */
void
XrlRipngV0p1Client::unmarshall_remove_rip_address(
	const XrlError&	e,
	XrlArgs*	a,
	RemoveRipAddressCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_set_rip_address_enabled(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const bool&	enabled,
	const SetRipAddressEnabledCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/set_rip_address_enabled");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("enabled", enabled);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_set_rip_address_enabled, cb));
}


/* Unmarshall set_rip_address_enabled */
void
XrlRipngV0p1Client::unmarshall_set_rip_address_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	SetRipAddressEnabledCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_rip_address_enabled(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const RipAddressEnabledCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/rip_address_enabled");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_rip_address_enabled, cb));
}


/* Unmarshall rip_address_enabled */
void
XrlRipngV0p1Client::unmarshall_rip_address_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	RipAddressEnabledCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    bool enabled;
    try {
	a->get("enabled", enabled);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &enabled);
}

bool
XrlRipngV0p1Client::send_set_cost(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const uint32_t&	cost,
	const SetCostCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/set_cost");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("cost", cost);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_set_cost, cb));
}


/* Unmarshall set_cost */
void
XrlRipngV0p1Client::unmarshall_set_cost(
	const XrlError&	e,
	XrlArgs*	a,
	SetCostCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_cost(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const CostCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/cost");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_cost, cb));
}


/* Unmarshall cost */
void
XrlRipngV0p1Client::unmarshall_cost(
	const XrlError&	e,
	XrlArgs*	a,
	CostCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t cost;
    try {
	a->get("cost", cost);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &cost);
}

bool
XrlRipngV0p1Client::send_set_horizon(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const string&	horizon,
	const SetHorizonCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/set_horizon");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("horizon", horizon);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_set_horizon, cb));
}


/* Unmarshall set_horizon */
void
XrlRipngV0p1Client::unmarshall_set_horizon(
	const XrlError&	e,
	XrlArgs*	a,
	SetHorizonCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_horizon(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const HorizonCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/horizon");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_horizon, cb));
}


/* Unmarshall horizon */
void
XrlRipngV0p1Client::unmarshall_horizon(
	const XrlError&	e,
	XrlArgs*	a,
	HorizonCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string horizon;
    try {
	a->get("horizon", horizon);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &horizon);
}

bool
XrlRipngV0p1Client::send_set_passive(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const bool&	passive,
	const SetPassiveCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/set_passive");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("passive", passive);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_set_passive, cb));
}


/* Unmarshall set_passive */
void
XrlRipngV0p1Client::unmarshall_set_passive(
	const XrlError&	e,
	XrlArgs*	a,
	SetPassiveCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_passive(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const PassiveCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/passive");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_passive, cb));
}


/* Unmarshall passive */
void
XrlRipngV0p1Client::unmarshall_passive(
	const XrlError&	e,
	XrlArgs*	a,
	PassiveCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    bool passive;
    try {
	a->get("passive", passive);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &passive);
}

bool
XrlRipngV0p1Client::send_set_accept_non_rip_requests(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const bool&	accept,
	const SetAcceptNonRipRequestsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/set_accept_non_rip_requests");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("accept", accept);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_set_accept_non_rip_requests, cb));
}


/* Unmarshall set_accept_non_rip_requests */
void
XrlRipngV0p1Client::unmarshall_set_accept_non_rip_requests(
	const XrlError&	e,
	XrlArgs*	a,
	SetAcceptNonRipRequestsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_accept_non_rip_requests(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const AcceptNonRipRequestsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/accept_non_rip_requests");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_accept_non_rip_requests, cb));
}


/* Unmarshall accept_non_rip_requests */
void
XrlRipngV0p1Client::unmarshall_accept_non_rip_requests(
	const XrlError&	e,
	XrlArgs*	a,
	AcceptNonRipRequestsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    bool accept;
    try {
	a->get("accept", accept);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &accept);
}

bool
XrlRipngV0p1Client::send_set_accept_default_route(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const bool&	accept,
	const SetAcceptDefaultRouteCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/set_accept_default_route");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("accept", accept);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_set_accept_default_route, cb));
}


/* Unmarshall set_accept_default_route */
void
XrlRipngV0p1Client::unmarshall_set_accept_default_route(
	const XrlError&	e,
	XrlArgs*	a,
	SetAcceptDefaultRouteCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_accept_default_route(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const AcceptDefaultRouteCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/accept_default_route");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_accept_default_route, cb));
}


/* Unmarshall accept_default_route */
void
XrlRipngV0p1Client::unmarshall_accept_default_route(
	const XrlError&	e,
	XrlArgs*	a,
	AcceptDefaultRouteCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    bool accept;
    try {
	a->get("accept", accept);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &accept);
}

bool
XrlRipngV0p1Client::send_set_advertise_default_route(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const bool&	advertise,
	const SetAdvertiseDefaultRouteCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/set_advertise_default_route");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("advertise", advertise);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_set_advertise_default_route, cb));
}


/* Unmarshall set_advertise_default_route */
void
XrlRipngV0p1Client::unmarshall_set_advertise_default_route(
	const XrlError&	e,
	XrlArgs*	a,
	SetAdvertiseDefaultRouteCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_advertise_default_route(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const AdvertiseDefaultRouteCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/advertise_default_route");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_advertise_default_route, cb));
}


/* Unmarshall advertise_default_route */
void
XrlRipngV0p1Client::unmarshall_advertise_default_route(
	const XrlError&	e,
	XrlArgs*	a,
	AdvertiseDefaultRouteCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    bool advertise;
    try {
	a->get("advertise", advertise);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &advertise);
}

bool
XrlRipngV0p1Client::send_set_route_expiry_seconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const uint32_t&	t_secs,
	const SetRouteExpirySecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/set_route_expiry_seconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("t_secs", t_secs);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_set_route_expiry_seconds, cb));
}


/* Unmarshall set_route_expiry_seconds */
void
XrlRipngV0p1Client::unmarshall_set_route_expiry_seconds(
	const XrlError&	e,
	XrlArgs*	a,
	SetRouteExpirySecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_route_expiry_seconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const RouteExpirySecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/route_expiry_seconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_route_expiry_seconds, cb));
}


/* Unmarshall route_expiry_seconds */
void
XrlRipngV0p1Client::unmarshall_route_expiry_seconds(
	const XrlError&	e,
	XrlArgs*	a,
	RouteExpirySecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t t_secs;
    try {
	a->get("t_secs", t_secs);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &t_secs);
}

bool
XrlRipngV0p1Client::send_set_route_deletion_seconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const uint32_t&	t_secs,
	const SetRouteDeletionSecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/set_route_deletion_seconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("t_secs", t_secs);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_set_route_deletion_seconds, cb));
}


/* Unmarshall set_route_deletion_seconds */
void
XrlRipngV0p1Client::unmarshall_set_route_deletion_seconds(
	const XrlError&	e,
	XrlArgs*	a,
	SetRouteDeletionSecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_route_deletion_seconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const RouteDeletionSecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/route_deletion_seconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_route_deletion_seconds, cb));
}


/* Unmarshall route_deletion_seconds */
void
XrlRipngV0p1Client::unmarshall_route_deletion_seconds(
	const XrlError&	e,
	XrlArgs*	a,
	RouteDeletionSecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t t_secs;
    try {
	a->get("t_secs", t_secs);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &t_secs);
}

bool
XrlRipngV0p1Client::send_set_table_request_seconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const uint32_t&	t_secs,
	const SetTableRequestSecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/set_table_request_seconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("t_secs", t_secs);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_set_table_request_seconds, cb));
}


/* Unmarshall set_table_request_seconds */
void
XrlRipngV0p1Client::unmarshall_set_table_request_seconds(
	const XrlError&	e,
	XrlArgs*	a,
	SetTableRequestSecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_table_request_seconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const TableRequestSecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/table_request_seconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_table_request_seconds, cb));
}


/* Unmarshall table_request_seconds */
void
XrlRipngV0p1Client::unmarshall_table_request_seconds(
	const XrlError&	e,
	XrlArgs*	a,
	TableRequestSecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t t_secs;
    try {
	a->get("t_secs", t_secs);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &t_secs);
}

bool
XrlRipngV0p1Client::send_set_unsolicited_response_min_seconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const uint32_t&	t_secs,
	const SetUnsolicitedResponseMinSecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/set_unsolicited_response_min_seconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("t_secs", t_secs);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_set_unsolicited_response_min_seconds, cb));
}


/* Unmarshall set_unsolicited_response_min_seconds */
void
XrlRipngV0p1Client::unmarshall_set_unsolicited_response_min_seconds(
	const XrlError&	e,
	XrlArgs*	a,
	SetUnsolicitedResponseMinSecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_unsolicited_response_min_seconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const UnsolicitedResponseMinSecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/unsolicited_response_min_seconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_unsolicited_response_min_seconds, cb));
}


/* Unmarshall unsolicited_response_min_seconds */
void
XrlRipngV0p1Client::unmarshall_unsolicited_response_min_seconds(
	const XrlError&	e,
	XrlArgs*	a,
	UnsolicitedResponseMinSecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t t_secs;
    try {
	a->get("t_secs", t_secs);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &t_secs);
}

bool
XrlRipngV0p1Client::send_set_unsolicited_response_max_seconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const uint32_t&	t_secs,
	const SetUnsolicitedResponseMaxSecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/set_unsolicited_response_max_seconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("t_secs", t_secs);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_set_unsolicited_response_max_seconds, cb));
}


/* Unmarshall set_unsolicited_response_max_seconds */
void
XrlRipngV0p1Client::unmarshall_set_unsolicited_response_max_seconds(
	const XrlError&	e,
	XrlArgs*	a,
	SetUnsolicitedResponseMaxSecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_unsolicited_response_max_seconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const UnsolicitedResponseMaxSecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/unsolicited_response_max_seconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_unsolicited_response_max_seconds, cb));
}


/* Unmarshall unsolicited_response_max_seconds */
void
XrlRipngV0p1Client::unmarshall_unsolicited_response_max_seconds(
	const XrlError&	e,
	XrlArgs*	a,
	UnsolicitedResponseMaxSecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t t_secs;
    try {
	a->get("t_secs", t_secs);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &t_secs);
}

bool
XrlRipngV0p1Client::send_set_triggered_update_min_seconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const uint32_t&	t_secs,
	const SetTriggeredUpdateMinSecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/set_triggered_update_min_seconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("t_secs", t_secs);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_set_triggered_update_min_seconds, cb));
}


/* Unmarshall set_triggered_update_min_seconds */
void
XrlRipngV0p1Client::unmarshall_set_triggered_update_min_seconds(
	const XrlError&	e,
	XrlArgs*	a,
	SetTriggeredUpdateMinSecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_triggered_update_min_seconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const TriggeredUpdateMinSecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/triggered_update_min_seconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_triggered_update_min_seconds, cb));
}


/* Unmarshall triggered_update_min_seconds */
void
XrlRipngV0p1Client::unmarshall_triggered_update_min_seconds(
	const XrlError&	e,
	XrlArgs*	a,
	TriggeredUpdateMinSecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t t_secs;
    try {
	a->get("t_secs", t_secs);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &t_secs);
}

bool
XrlRipngV0p1Client::send_set_triggered_update_max_seconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const uint32_t&	t_secs,
	const SetTriggeredUpdateMaxSecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/set_triggered_update_max_seconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("t_secs", t_secs);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_set_triggered_update_max_seconds, cb));
}


/* Unmarshall set_triggered_update_max_seconds */
void
XrlRipngV0p1Client::unmarshall_set_triggered_update_max_seconds(
	const XrlError&	e,
	XrlArgs*	a,
	SetTriggeredUpdateMaxSecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_triggered_update_max_seconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const TriggeredUpdateMaxSecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/triggered_update_max_seconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_triggered_update_max_seconds, cb));
}


/* Unmarshall triggered_update_max_seconds */
void
XrlRipngV0p1Client::unmarshall_triggered_update_max_seconds(
	const XrlError&	e,
	XrlArgs*	a,
	TriggeredUpdateMaxSecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t t_secs;
    try {
	a->get("t_secs", t_secs);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &t_secs);
}

bool
XrlRipngV0p1Client::send_set_interpacket_delay_milliseconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const uint32_t&	t_msecs,
	const SetInterpacketDelayMillisecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/set_interpacket_delay_milliseconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("t_msecs", t_msecs);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_set_interpacket_delay_milliseconds, cb));
}


/* Unmarshall set_interpacket_delay_milliseconds */
void
XrlRipngV0p1Client::unmarshall_set_interpacket_delay_milliseconds(
	const XrlError&	e,
	XrlArgs*	a,
	SetInterpacketDelayMillisecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_interpacket_delay_milliseconds(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const InterpacketDelayMillisecondsCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/interpacket_delay_milliseconds");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_interpacket_delay_milliseconds, cb));
}


/* Unmarshall interpacket_delay_milliseconds */
void
XrlRipngV0p1Client::unmarshall_interpacket_delay_milliseconds(
	const XrlError&	e,
	XrlArgs*	a,
	InterpacketDelayMillisecondsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t t_msecs;
    try {
	a->get("t_msecs", t_msecs);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &t_msecs);
}

bool
XrlRipngV0p1Client::send_rip_address_status(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const RipAddressStatusCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/rip_address_status");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_rip_address_status, cb));
}


/* Unmarshall rip_address_status */
void
XrlRipngV0p1Client::unmarshall_rip_address_status(
	const XrlError&	e,
	XrlArgs*	a,
	RipAddressStatusCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string status;
    try {
	a->get("status", status);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &status);
}

bool
XrlRipngV0p1Client::send_get_counters(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const GetCountersCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/get_counters");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_get_counters, cb));
}


/* Unmarshall get_counters */
void
XrlRipngV0p1Client::unmarshall_get_counters(
	const XrlError&	e,
	XrlArgs*	a,
	GetCountersCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0);
	return;
    } else if (a && a->size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != 2)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    XrlAtomList counter_descriptions;
    XrlAtomList counter_values;
    try {
	a->get("counter_descriptions", counter_descriptions);
	a->get("counter_values", counter_values);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &counter_descriptions, &counter_values);
}

bool
XrlRipngV0p1Client::send_get_peers(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const GetPeersCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/get_peers");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_get_peers, cb));
}


/* Unmarshall get_peers */
void
XrlRipngV0p1Client::unmarshall_get_peers(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeersCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    XrlAtomList peers;
    try {
	a->get("peers", peers);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &peers);
}

bool
XrlRipngV0p1Client::send_get_all_peers(
	const char*	the_tgt,
	const GetAllPeersCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/get_all_peers");
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_get_all_peers, cb));
}


/* Unmarshall get_all_peers */
void
XrlRipngV0p1Client::unmarshall_get_all_peers(
	const XrlError&	e,
	XrlArgs*	a,
	GetAllPeersCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0, 0, 0);
	return;
    } else if (a && a->size() != 4) {
	XLOG_ERROR("Wrong number of arguments (%u != 4)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0);
	return;
    }
    XrlAtomList peers;
    XrlAtomList ifnames;
    XrlAtomList vifnames;
    XrlAtomList addrs;
    try {
	a->get("peers", peers);
	a->get("ifnames", ifnames);
	a->get("vifnames", vifnames);
	a->get("addrs", addrs);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0);
	return;
    }
    cb->dispatch(e, &peers, &ifnames, &vifnames, &addrs);
}

bool
XrlRipngV0p1Client::send_get_peer_counters(
	const char*	the_tgt,
	const string&	ifname,
	const string&	vifname,
	const IPv6&	addr,
	const IPv6&	peer,
	const GetPeerCountersCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/get_peer_counters");
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("addr", addr);
    x.args().add("peer", peer);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_get_peer_counters, cb));
}


/* Unmarshall get_peer_counters */
void
XrlRipngV0p1Client::unmarshall_get_peer_counters(
	const XrlError&	e,
	XrlArgs*	a,
	GetPeerCountersCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0, 0);
	return;
    } else if (a && a->size() != 3) {
	XLOG_ERROR("Wrong number of arguments (%u != 3)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0);
	return;
    }
    XrlAtomList counter_descriptions;
    XrlAtomList counter_values;
    uint32_t peer_last_active;
    try {
	a->get("counter_descriptions", counter_descriptions);
	a->get("counter_values", counter_values);
	a->get("peer_last_active", peer_last_active);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0);
	return;
    }
    cb->dispatch(e, &counter_descriptions, &counter_values, &peer_last_active);
}

bool
XrlRipngV0p1Client::send_add_static_route(
	const char*	the_tgt,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const uint32_t&	cost,
	const AddStaticRouteCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/add_static_route");
    x.args().add("network", network);
    x.args().add("nexthop", nexthop);
    x.args().add("cost", cost);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_add_static_route, cb));
}


/* Unmarshall add_static_route */
void
XrlRipngV0p1Client::unmarshall_add_static_route(
	const XrlError&	e,
	XrlArgs*	a,
	AddStaticRouteCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRipngV0p1Client::send_delete_static_route(
	const char*	the_tgt,
	const IPv6Net&	network,
	const DeleteStaticRouteCB&	cb
)
{
    Xrl x(the_tgt, "ripng/0.1/delete_static_route");
    x.args().add("network", network);
    return _sender->send(x, callback(this, &XrlRipngV0p1Client::unmarshall_delete_static_route, cb));
}


/* Unmarshall delete_static_route */
void
XrlRipngV0p1Client::unmarshall_delete_static_route(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteStaticRouteCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}
