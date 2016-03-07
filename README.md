# ft_ls
A 42 project
bchaleil

Attention !
FRANGLISH
Voir man ls pour les details.

Function allowed.
opendir / readdir / closedir

La function opendir ouvre un dossier avec son nom et renvois un directory stream.
Un pointeur NULL est retourne.
En cas d'erreur est errno est fixe.

La function readdir return un pointeur sur le fichier suivant.
Return NULL si arrive a la fin.
En cas d'erreur errno est fixe.

La function closedir ferme un directory stream et free.
`Retourne 0 en cas de succes et -1 en cas de failure.
-----------------------------------------------------------------------------
stat / lstat

La function stat obient des informations sur le fichier pointe par le params path. Les perms ne sont pas requise mais tous les directories liste ds le pathname doivent etre cherchable

La function lstat est comme stat sauf dans le cas ou le fichier est un symlink lstat retourne les informations a propos du link tandis que stat returns a propos du fichier link.
`int	stat(const char *restrict path, struct stat *restrict buf);`
La struct renvoye par ses fonctions.

`struct stat { /* when _DARWIN_FEATURE_64_BIT_INODE is defined */
	 dev_t           st_dev;           /* ID of device containing file */
	 mode_t          st_mode;          /* Mode of file (see below) */
	 nlink_t         st_nlink;         /* Number of hard links */
	 ino_t           st_ino;           /* File serial number */
	 uid_t           st_uid;           /* User ID of the file */
	 gid_t           st_gid;           /* Group ID of the file */
	 dev_t           st_rdev;          /* Device ID */
	 struct timespec st_atimespec;     /* time of last access */
	 struct timespec st_mtimespec;     /* time of last data modification */
	 struct timespec st_ctimespec;     /* time of last status change */
	 struct timespec st_birthtimespec; /* time of file creation(birth) */
	 off_t           st_size;          /* file size, in bytes */
	 blkcnt_t        st_blocks;        /* blocks allocated for file */
	 blksize_t       st_blksize;       /* optimal blocksize for I/O */
	 uint32_t        st_flags;         /* user defined flags for file */
	 uint32_t        st_gen;           /* file generation number */
	 int32_t         st_lspare;        /* RESERVED: DO NOT USE! */
	 int64_t         st_qspare[2];     /* RESERVED: DO NOT USE! */
 };
-----------------------------------------------------------------------------
getpwuid / getgrgid

La fonction getpwuid cherche la base de donnees des passwords dudit login, user uid ou user uuid respectivement et retourne toujours la premiere occurence.
`struct passw	*getpwuid(uid_t uid);`

Retourne une struct.
struct passwd {
	   char    *pw_name;       /* user name */
	   char    *pw_passwd;     /* encrypted password */
	   uid_t   pw_uid;         /* user uid */
	   gid_t   pw_gid;         /* user gid */
	   time_t  pw_change;      /* password change time */
	   char    *pw_class;      /* user access class */
	   char    *pw_gecos;      /* Honeywell login info */
	   char    *pw_dir;        /* home directory */
	   char    *pw_shell;      /* default shell */
	   time_t  pw_expire;      /* account expiration */
	   int     pw_fields;      /* internal: fields filled in */
};

La fonction getgrgid cherche la base de donnee du groupe et retourne la premiere occurence.
`struct group	*getgrgid(gid_t gid);`

struct group {
		char    *gr_name;       /* group name */
        char    *gr_passwd;     /* group password */
        gid_t   gr_gid;         /* group id */
        char    **gr_mem;       /* group members */
};

-----------------------------------------------------------------------------
time / ctime
The time function returns the value of time since the Epoch.

The ctime take as argument a time value adjust for the current time zone and return a pointer to a 26 char string of the form:
	Thu Nov 24 18:22:48 1986\n\0

-----------------------------------------------------------------------------

La fonction readlink permet de lire le contenu du lien symbolique.

`ssize_t		readlink(const char *restrict path, char *restrict buf, size_t bufsize);`

-----------------------------------------------------------------------------

perror / strerror
La function perror trouve le message d'erreur qui correspond a la valeur ACTUEL d'errno et l'ecris suivi d un \n. Si largument n est pas nul alors le contenu est 
concatene a lerreur

La function strerror accepte une valeur de errno et retourne un pointeur au msg aui correspond.

Partie obligatoire:
-l : List in long format.
-R : Recursively list subdirectories encountered.
-a : Include directory entries whose name begin by a dot (.) .
-r : Reverse order of the sort to get reverse lexicographical order or the oldest entries first.
-t : Sort by time modified before sorting lexicographical order.

option l more info:

En cas d'erreur le programme ls renverra la derniere valeur de errno.
Si tout c'est bien deroule ls renverra 0.
