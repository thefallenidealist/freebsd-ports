# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	statistics
PORTVERSION=	0.14.0.2
PORTREVISION=	2
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Library of statistical types, data, and functions

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson>=0.6.0.0 base-orphans erf math-functions>=0.1.5.2 monad-par>=0.3.4 \
		mwc-random>=0.13.0.0 primitive>=0.3 vector>=0.10 \
		vector-algorithms>=0.4 vector-binary-instances>=0.2.1 vector-th-unbox

INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
