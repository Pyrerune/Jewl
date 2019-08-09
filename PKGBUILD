# Maintainer: Pyrerune <pyrerune@gmail.com>
pkgname=Jewl
pkgver=4.1.1
pkgrel=1
arch=('x86_64' 'i686')
pkgdesc="The Jewl programming language interpreter"
url="https://github.com/pyrerune/Jewl"
license=('MIT')
source=("${pkgname}-${pkgver}.tar.xz")
md5sums=('SKIP')
build() {
	./configure -p $pkgdir/usr/bin
	
	make
}
package() {
	mkdir -p "${pkgdir}/usr/bin"
	make install
}