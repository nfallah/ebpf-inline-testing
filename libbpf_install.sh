get_latest_release() {
    git ls-remote --tags "https://github.com/libbpf/libbpf" | cut -d/ -f3 | tail -n1
}

if [ ! -d "libbpf" ]; then
    git clone "https://github.com/libbpf/libbpf.git"
else
    cd libbpf
    git reset --hard
    git clean -fdx
    cd ..
fi

if [ $# -eq 1 ]; then
    version=$1
else
    version=$(get_latest_release)
fi

cd libbpf
git checkout $version
cd src
make -j$(nproc)
cd ../..
echo "Successfully installed libbpf $version"