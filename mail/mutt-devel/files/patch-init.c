--- init.c.orig	Wed Jul 24 10:41:29 2002
+++ init.c	Sat May  3 08:46:29 2003
@@ -1707,7 +1707,11 @@
 void mutt_init (int skip_sys_rc, LIST *commands)
 {
   struct passwd *pw;
+#if __FreeBSD_version < 500000
+  char nodename[STRING];
+#else
   struct utsname utsname;
+#endif
   char *p, buffer[STRING], error[STRING];
   int i, default_rc = 0, need_pause = 0;
   BUFFER err;
@@ -1765,16 +1769,21 @@
 #endif
 
   /* And about the host... */
+#if __FreeBSD_version < 500000
+  gethostname(nodename, sizeof (nodename));
+#else
   uname (&utsname);
+  strfcpy (nodename, utsname.nodename, sizeof (nodename));
+#endif
   /* some systems report the FQDN instead of just the hostname */
-  if ((p = strchr (utsname.nodename, '.')))
+  if ((p = strchr (nodename, '.')))
   {
-    Hostname = mutt_substrdup (utsname.nodename, p);
+    Hostname = mutt_substrdup (nodename, p);
     p++;
     strfcpy (buffer, p, sizeof (buffer)); /* save the domain for below */
   }
   else
-    Hostname = safe_strdup (utsname.nodename);
+    Hostname = safe_strdup (nodename);
 
 #ifndef DOMAIN
 #define DOMAIN buffer
--- init.c.orig
+++ init.c
@@ -1371,17 +1371,6 @@
   pid_t pid;
   struct stat s;
 
-  if (stat (rcfile, &s) < 0)
-  {
-    snprintf (err->data, err->dsize, _("%s: stat: %s"), rcfile, strerror (errno));
-    return (-1);
-  }
-  if (!S_ISREG (s.st_mode))
-  {
-    snprintf (err->data, err->dsize, _("%s: not a regular file"), rcfile);
-    return (-1);
-  }
-
   if ((f = mutt_open_read (rcfile, &pid)) == NULL)
   {
     snprintf (err->data, err->dsize, "%s: %s", rcfile, strerror (errno));

