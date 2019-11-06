FROM su2code/build-su2
ENV LANG C.UTF-8
RUN apt-get update && apt-get install -y \
    clang \
    cmake \
    patch \
    libssl-dev \
    lzma-dev \
    libxml2-dev 



RUN git clone https://github.com/tpoechtrager/osxcross && cd osxcross 

COPY MacOSX10.15.sdk.tar.xz /osxcross/tarballs/MacOSX10.15.sdk.tar.xz

RUN cd osxcross && UNATTENDED=1 ./build.sh 

COPY hostfile_darwin /hostfile_darwin

# Copies your code file from your action repository to the filesystem path `/` of the container
COPY compileSU2.sh /compileSU2.sh

# Code file to execute when the docker container starts up (`entrypoint.sh`)
ENTRYPOINT ["/compileSU2.sh"]
