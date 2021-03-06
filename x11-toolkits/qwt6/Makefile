# $FreeBSD$

PORTNAME=	qwt
PORTVERSION=	6.1.3
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
PKGNAMESUFFIX=	6-${FLAVOR}

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Qt Widgets for Technical Applications

FLAVORS=	qt4 qt5
FLAVOR?=	${FLAVORS:[1]}

USES=		gmake qmake tar:bzip2
USE_GL=		gl
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/qwt6-${FLAVOR}
PORTDOCS=	*
PLIST_SUB=	SHLIB_VER=${PORTVERSION} \
		SHLIB_SHVER=${PORTVERSION:R}

QMAKE_ARGS+=	PLUGINDIR=${PREFIX}/${QT_PLUGINDIR_REL}

.if ${FLAVOR} == qt4
USE_QT4=	corelib designer gui opengl svg xml moc_build rcc_build script
.else
USE_QT5=	buildtools_build widgets gui core designer gui opengl svg xml printsupport concurrent
.endif

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/INSTALLS.*doc/d' ${WRKSRC}/doc/doc.pro
	@${REINPLACE_CMD} -e 's/%%QT_VERSION%%/${FLAVOR:S/qt//}/g' \
			-e 's|%%QT_INCDIR%%|${QT_INCDIR}|g' \
			-e 's|%%QT_LIBDIR%%|${QT_LIBDIR}|g' \
			-e 's|%%QT_MKSPECDIR%%|${QT_MKSPECDIR}|g' \
			${WRKSRC}/qwtconfig.pri

post-install-DOCS-on:
	@(cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
