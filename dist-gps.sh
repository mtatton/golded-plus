#!/bin/sh

# Create a archives 'gps*.tar.bz2' and 'gps*.tb2' with all source tree

date=`date +%Y%m%d`
shortdate=`echo ${date} | sed s/^...//`
shortname=../gps${shortdate}.tb2
name=gps115-${date}.tar.bz2

cd .. ; tar -jcf ${name} \
	--exclude CVS \
	--exclude golded+/golded3/mygolded.h \
	--exclude golded+/goldlib/gall/obj \
	--exclude golded+/obj \
	--exclude golded+/lib \
	--exclude golded+/bin \
	--exclude golded+/Release \
	--exclude 'golded+/*.bat' \
	--exclude 'golded+/*.BAT' \
	--exclude 'golded+/*.cmd' \
	--exclude 'golded+/*.CMD' \
	--exclude '.#*' \
	--exclude '*.orig' \
	--exclude 'bld*.inc' \
	--exclude '*.diff' \
	--exclude '*.tar.gz' \
	--exclude '*.tgz' \
	--exclude '*.tar.bz' \
	--exclude '*.tbz' \
	--exclude '*.tar.bz2' \
	--exclude '*.tb2' \
	--exclude '*.cpz' \
	--exclude '*.rar' \
	--exclude '*.zip' \
	--exclude '*.7z' \
	--exclude '*.exe' \
	--exclude '*.a' \
	--exclude '*.o' \
	golded+

cp ${name} ${shortname}
