cmd_/work/openwrt/build_dir/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/linux-dev//include/linux/wimax/.install := bash scripts/headers_install.sh /work/openwrt/build_dir/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/linux-dev//include/linux/wimax ./include/uapi/linux/wimax i2400m.h; bash scripts/headers_install.sh /work/openwrt/build_dir/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/linux-dev//include/linux/wimax ./include/linux/wimax ; bash scripts/headers_install.sh /work/openwrt/build_dir/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/linux-dev//include/linux/wimax ./include/generated/uapi/linux/wimax ; for F in ; do echo "\#include <asm-generic/$$F>" > /work/openwrt/build_dir/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/linux-dev//include/linux/wimax/$$F; done; touch /work/openwrt/build_dir/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/linux-dev//include/linux/wimax/.install
