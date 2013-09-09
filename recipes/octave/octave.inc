DESCRIPTION = "Matlab alternative for numerical computations"
HOMEPAGE = "http://www.gnu.org/software/octave/"
SECTION = "console/scientific"
LICENSE = "GPL"
DEPENDS = "readline ncurses fftw gperf-native"
RDEPENDS = "libfftw3"
# fftw compiled with --disable-fortran

ARM_INSTRUCTION_SET = "arm"

TARGET_CC_ARCH += "${LDFLAGS}"

inherit autotools

EXTRA_OECONF = "F77=arm-angstrom-linux-gnueabi-gfortran \
                --without-hdf5 --without-glpk \
                --without-umfpack --with-gnutls\
                --without-colamd --without-ccolamd --without-cholmod \
                --with-blas=${PKG_CONFIG_SYSROOT_DIR}/${D}/${libdir}/libblas.a \
                --with-lapack=${PKG_CONFIG_SYSROOT_DIR}/${D}/${libdir}/liblapack.a \
                --disable-docs --with-x=no \
                --disable-freetypetest --without-framework-carbon \
                gl_cv_func_gettimeofday_clobber=no \
                "

PACKAGES += "octave-m"

# octave-m provides matlab routines in .m file format
FILES_${PN}-m = "${datadir}/${PN}/*"
