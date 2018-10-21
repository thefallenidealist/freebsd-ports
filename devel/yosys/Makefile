# Created by: Johnny Sorocil <jsorocil@gmail.com>
# $FreeBSD$

PORTNAME=	yosys
DISTVERSION=	0.8
CATEGORIES=	devel

MAINTAINER=	jsorocil@gmail.com
COMMENT=	Yosys Open SYnthesis Suite

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to build: /bin/sh: clang: not found

BUILD_DEPENDS=	abc:cad/abc \
		bash:shells/bash \
		gawk:lang/gawk
LIB_DEPENDS=	libffi.so:devel/libffi

USES=		bison gmake pkgconfig python:3.6+ readline shebangfix tcl
SHEBANG_FILES=	backends/smt2/smtbmc.py \
		misc/yosys-config.in

USE_GITHUB=	yes
GH_ACCOUNT=	YosysHQ
GH_TAGNAME=	5706e90802fdf51a476e769790f6b5b526c57572

BINARY_ALIAS=	python3=${PYTHON_CMD} tclsh=${TCLSH}
MAKE_ARGS=	ABCEXTERNAL=abc

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/yosys

.include <bsd.port.mk>
