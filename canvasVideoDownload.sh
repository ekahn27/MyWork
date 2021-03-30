$!/bin/bash
ffmpeg -protocl_whitelist file,http,https,tcp,tls,crypto -i $1 -c copy $2
