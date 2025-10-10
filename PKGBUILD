pkgname=cpputilities
pkgver=0.0.7
pkgrel=1
pkgdesc="Many useful utilities in one place!"
arch=('any')
url='https://github.com/Pro7777tim/CPPutilities'
license=('GPL3')
makedepends=("gcc>=13.0")
depends=('python>=3.12')
source=()
options=('!debug')

#=========================================
build() {
   bash "$srcdir/../launch/_compilation.sh"
}

#=========================================
package() {
   install -Dm755 "$srcdir/../launch/scr/sh/cpput" "$pkgdir/usr/bin/cpput"
   install -Dm644 "$srcdir/../source/scr/py/timerWindow.py" "$pkgdir/usr/local/bin/cpputilities/source/scr/py/timerWindow.py"
   install -Dm755 "$srcdir/../bin/main"* "$pkgdir/usr/local/bin/cpputilities/bin/main"
}
