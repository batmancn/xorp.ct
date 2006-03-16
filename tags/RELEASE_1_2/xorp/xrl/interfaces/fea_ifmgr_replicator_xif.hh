/*
 * Copyright (c) 2001-2005 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/fea_ifmgr_replicator_xif.hh,v 1.4 2004/06/10 22:41:59 hodson Exp $
 */

#ifndef __XRL_INTERFACES_FEA_IFMGR_REPLICATOR_XIF_HH__
#define __XRL_INTERFACES_FEA_IFMGR_REPLICATOR_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifFeaIfmgrReplicator"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlIfmgrReplicatorV0p1Client {
public:
    XrlIfmgrReplicatorV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlIfmgrReplicatorV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr RegisterIfmgrMirrorCB;
    /**
     *  Send Xrl intended to:
     *
     *  Register remote mirror of interface state.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_register_ifmgr_mirror(
	const char*	target_name,
	const string&	clientname,
	const RegisterIfmgrMirrorCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr UnregisterIfmgrMirrorCB;
    /**
     *  Send Xrl intended to:
     *
     *  Register remote mirror of interface state.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_unregister_ifmgr_mirror(
	const char*	target_name,
	const string&	clientname,
	const UnregisterIfmgrMirrorCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_register_ifmgr_mirror(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterIfmgrMirrorCB		cb
    );

    void unmarshall_unregister_ifmgr_mirror(
	const XrlError&	e,
	XrlArgs*	a,
	UnregisterIfmgrMirrorCB		cb
    );

};

#endif /* __XRL_INTERFACES_FEA_IFMGR_REPLICATOR_XIF_HH__ */