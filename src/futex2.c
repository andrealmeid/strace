/*
 * Copyright (c) 2002-2003 Roland McGrath  <roland@redhat.com>
 * Copyright (c) 2007-2008 Ulrich Drepper <drepper@redhat.com>
 * Copyright (c) 2009 Andreas Schwab <schwab@redhat.com>
 * Copyright (c) 2014-2015 Dmitry V. Levin <ldv@strace.io>
 * Copyright (c) 2014-2021 The strace developers.
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include "defs.h"

#include "xlat/futex2ops.h"

SYS_FUNC(futex_wait)
{
	const kernel_ulong_t uaddr = tcp->u_arg[0];
	const unsigned int val = tcp->u_arg[1];
	const int flags = tcp->u_arg[2];
	const kernel_ulong_t timeout = tcp->u_arg[3];

	printaddr(uaddr);
	tprint_arg_next();
	PRINT_VAL_U(val);
	tprint_arg_next();
	printxval(futex2ops, flags, "FUTEX_???");
	tprint_arg_next();
	print_timespec64(tcp, timeout);

	return RVAL_DECODED;
}

SYS_FUNC(futex_wake)
{
	const kernel_ulong_t uaddr = tcp->u_arg[0];
	const unsigned int val = tcp->u_arg[1];
	const int flags = tcp->u_arg[2];

	printaddr(uaddr);
	tprint_arg_next();
	PRINT_VAL_U(val);
	tprint_arg_next();
	printxval(futex2ops, flags, "FUTEX_???");

	return RVAL_DECODED;
}
