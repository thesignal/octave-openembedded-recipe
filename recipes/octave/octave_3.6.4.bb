require octave.inc

PR = "r1"
SRC_URI = "ftp://ftp.gnu.org/gnu/octave/${PN}-${PV}.tar.gz"

SRC_URI[md5sum] = "d51e249103b9020ecc305de509c61e4e"
SRC_URI[sha256sum] = "46e1675b5e3225ed2355446cbe2d64f9a2b930ef103325589eff043e65c10f54"

LIC_FILES_CHKSUM = "file://${WORKDIR}/${PN}-${PV}/COPYING;md5=d32239bcb673463ab874e80d47fae504"

PACKAGES =+ "libcruft liboctave liboctinterp \
       libcruft-dev liboctave-dev liboctinterp-dev \
             libcruft-dbg liboctave-dbg liboctinterp-dbg octave-oct"

FILES_libcruft-dev = "${libdir}/${PN}/${PV}/libcruft.so"
FILES_libcruft-dbg += "${libdir}/${PN}/${PV}/.debug/libcruft*"

FILES_liboctave-dev = "${libdir}/${PN}/${PV}/liboctave.so"
FILES_liboctave-dbg += "${libdir}/${PN}/${PV}/.debug/liboctave*"

FILES_liboctinterp-dev = "${libdir}/${PN}/${PV}/liboctinterp.so"
FILES_liboctinterp-dbg += "${libdir}/${PN}/${PV}/.debug/liboctinterp*"

# octave-oct provides subroutines in .oct file format
FILES_${PN}-oct = "${libexecdir}/${PN}/${PV}/oct/${TARGET_SYS}/.debug/*.oct"

# debug files
FILES_${PN}-dbg += "${libdir}/${PN}/${PV}/oct/${TARGET_SYS}/.debug"
