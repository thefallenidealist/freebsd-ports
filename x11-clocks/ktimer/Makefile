# $FreeBSD$

PORTNAME=	ktimer
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11-clocks kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Countdown launcher for KDE

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons doctools ecm i18n iconthemes jobwidgets kio \
		notifications service widgetsaddons xmlgui
USE_QT5=	core dbus gui network widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
