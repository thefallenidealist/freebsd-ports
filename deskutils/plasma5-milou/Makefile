# $FreeBSD$

PORTNAME=	milou
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	deskutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 Plasmoid for search

USES=		cmake:outsource compiler:c++11-lib cpe gettext kde:5 tar:xz
USE_KDE=	auth codecs config coreaddons i18n kdeclarative package \
		plasma-framework runner service
USE_QT5=	core gui network qml quick script testlib widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
