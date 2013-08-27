# bitbake version: 1.16
DESCRIPTION = "Matlab alternative for numerical computations"
HOMEPAGE = "http://www.gnu.org/software/octave/"
SECTION = "console/scientific"
LICENSE = "GPL"
DEPENDS = "readline ncurses fftw gperf-native blas lapack"
RDEPENDS = "${PN} libfftw3"
# fftw compiled with --disable-fortran

ARM_INSTRUCTION_SET = "arm"

TARGET_CC_ARCH += "${LDFLAGS}"

inherit autotools

# adapt F77 for your application, also, adapt configure for your application

EXTRA_OECONF = "F77=arm-angstrom-linux-gnueabi-gfortran \
                --without-hdf5 --without-glpk \
                --without-umfpack --with-gnutls\
                --without-colamd --without-ccolamd --without-cholmod \
                --without-cxsparse --disable-docs --with-x=no \
                --enable-shared \
                --disable-freetypetest --without-framework-carbon \
                "

PACKAGES += "octave-m"

# octave-m provides matlab routines in .m file format
FILES_${PN}-m = "${datadir}/${PN}/*"
