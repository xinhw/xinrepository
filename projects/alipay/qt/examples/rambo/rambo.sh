#!/bin/sh
appname=`basename $0 | sed s,\.sh$,,`

dirname=`dirname $0`
tmp="${dirname#?}"

if [ "${dirname%$tmp}" != "/" ]; then
dirname=$PWD/$dirname
fi

libQtCore=$dirname/libQtCore.so.4
libQtGui=$dirname/libQtGui.so.4
libQtNetwork=$dirname/libQtNetwork.so.4

if [ ! -f "$libQtCore" ]; then
 ln $dirname/libQtCore.so.4.8.5 $libQtCore
fi

if [ ! -f "$libQtGui" ]; then
 ln $dirname/libQtGui.so.4.8.5 $libQtGui
fi

if [ ! -f "$libQtNetwork" ]; then
 ln $dirname/libQtNetwork.so.4.8.5 $libQtNetwork
fi

LD_LIBRARY_PATH=$dirname
export LD_LIBRARY_PATH

if test -e /dev/fb0; then
width=`fbset | grep 'geometry' | awk '{print $2}'`
height=`fbset | grep 'geometry' | awk '{print $3}'`

let height=height-38
geo=`echo $width\x$height+0+0`
fi

pidof matrix_gui > /dev/null 2>&1
if [ $? == 0 ]
then
        $dirname/$appname -geometry $geo
else
export TSLIB_TSDEVICE=/dev/input/touchscreen0
export QWS_MOUSE_PROTO=Tslib:/dev/input/touchscreen0
        $dirname/$appname -qws -geometry $geo
fi

