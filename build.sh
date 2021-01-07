#!/bin/sh

cc=gcc

gtk_flags=`pkg-config --libs --cflags gtk+-2.0`
gtkmm_flags=`pkg-config --libs --cflags gtkmm-2.4`
glade_flags=`pkg-config --libs --cflags libglade-2.0`
mysql_flags=`mysql_config --libs --cflags`


for x in *.c*
do
  files="$files $x"
done
echo "Compilando: $files"
echo ""


extra_flags="  -L/usr/local/lib -Iinclude/ -I../include/ -lstdc++"
output=libemface.so.1

echo "..."

echo "$cc $gtkmm_flags  $files  $extra_flags -o $output"

echo "..."

$cc -g  -fPIC -shared -Wl,-soname,libinterface.so.1 $gtkmm_flags $files $extra_flags  -o $output

echo ""
