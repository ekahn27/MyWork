## Instructions to Compress-Archive/Decompress-Unarchive with Tar

### Compress and Archive <br>
*tar -czvf name-of-arhive.tar.gz /path/to/directory-or-file*

- -c: **C**reate archive
- -z: Compress archive w/ g**z**ip
- -v: **V**erbose
- -f: Allows you to specify the **f**ilename of the archive

Say you have a directory named "stuff" in the current directory and you want to
save it to a file named archive.tar.gz. You'd run ...

*tar -czvf archive.tar.gz stuff*

*tar -cjvf* can be used instead (j instead of z) to use bzip2 (slower but more compression)

### Decompress and Exctract <br>
*tar -xzvf name-of-archive.tar.gz -C /directory/to/extract/to*

- -x: E**x**tract archive
- -j: replace -z w/ -j if bzip2 compression
