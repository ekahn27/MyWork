## Instructions to Compress-Archive/Decompress-Unarchive with Tar

### Compress and Archive <br>
**_tar -czvf name-of-arhive.tar.gz /path/to/directory-or-file_**

- -c: **C**reate archive
- -z: Compress archive w/ g**z**ip
- -v: **V**erbose
- -f: Allows you to specify the **f**ilename of the archive

Say you have a directory named "stuff" in the current directory and you want to
save it to a file named archive.tar.gz. You'd run ...

_tar -czvf archive.tar.gz stuff_

_tar -cjvf_ can be used instead (j instead of z) to use bzip2 (slower but more compression)


### Decompress and Exctract <br>
**_tar -xzvf name-of-archive.tar.gz -C /directory/to/extract/to_**

- -x: E**x**tract archive
- -j: replace -z with -j if bzip2 compression


For for info go [here](https://www.howtogeek.com/248780/how-to-compress-and-extract-files-using-the-tar-command-on-linux/)
