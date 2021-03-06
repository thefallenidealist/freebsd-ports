# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opensmtpd
PORTVERSION=	201606220754
DISTVERSIONSUFFIX=	p1
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.opensmtpd.org/archives/ \
		http://distfiles.pirateparty.in/ashish/
PKGNAMESUFFIX=	-devel

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Security- and simplicity-focused SMTP server from OpenBSD

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent

OPTIONS_DEFINE=		CA_BUNDLE LIBASR MAILERCONF PAM TABLE_DB

OPTIONS_DEFAULT=	CA_BUNDLE PAM TABLE_DB

CA_BUNDLE_DESC=		Install CA bundle for SSL
LIBASR_DESC=		Use stable version of libasr
MAILERCONF_DESC=	Activate OpenSMTPD in mailer.conf(5)
TABLE_DB_DESC=		Build table-db plugin (aliases)

USES=		cpe groff libtool ssl
GNU_CONFIGURE=	yes

CPE_VENDOR=	openbsd

USE_RC_SUBR=	smtpd
SUB_FILES=	pkg-install pkg-deinstall pkg-message

CONFLICTS_INSTALL=	postfix-[0-9]* sendmail-[0-9]* opensmtpd-[0-9]*

USERS=		_smtpd _smtpq
GROUPS=		_smtpd _smtpq

OPTIONS_SUB=	yes

CA_BUNDLE_CONFIGURE_WITH=	path-CAfile=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

LIBASR_LIB_DEPENDS=	libasr.so:dns/libasr
LIBASR_LIB_DEPENDS_OFF=	libasr.so:dns/libasr-devel

PAM_CONFIGURE_WITH=	auth-pam=smtpd
TABLE_DB_CONFIGURE_WITH=	table-db

CONFIGURE_ARGS+=	--with-libasr=${LOCALBASE} \
			--with-libevent=${LOCALBASE} \
			--with-libssl=${OPENSSLBASE} \
			--sysconfdir=${PREFIX}/etc/mail/

post-patch:
	${REINPLACE_CMD} -e '/chmod 2555/d' ${WRKSRC}/mk/smtpctl/Makefile.in
	# https://github.com/OpenSMTPD/OpenSMTPD/issues/700
	${REINPLACE_CMD} -r -e \
		'/SMTPD_VERSION/s/"[^"]+"$$/"${PORTVERSION}${DISTVERSIONSUFFIX}"/' \
		${WRKSRC}/smtpd/smtpd.h

post-install-TABLE_DB-on:
	@${LN} -sf ${PREFIX}/sbin/smtpctl ${STAGEDIR}${PREFIX}/libexec/opensmtpd/makemap

.include <bsd.port.mk>
