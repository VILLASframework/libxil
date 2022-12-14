Name:    libxil
Version: 1.1
Vendor: Institute for Automation of Complex Power Systems
Packager: Steffen Vogel <post@steffenvogel.de>
Release: 1%{?dist}
Summary: Modified Xilinx drivers for VILLASnode

License: Xilinx BSD?
URL:     https://git.rwth-aachen.de/VILLASframework/libxil
#Source0: https://git.rwth-aachen.de/VILLASframework/libxil/repository/archive.tar.gz?ref=%{version}
Source0: libxil-0.1.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

BuildRequires: gcc cmake

%description

Source: https://github.com/Xilinx/embeddedsw

%package devel

Summary:        Headers and libraries for building apps that use libxil
Group:          Development/Libraries
Requires:       %{name} = %{version}-%{release}

%description devel

The development headers for libxil.

%prep
%setup -q

%build
mkdir -p build
cd build
%cmake -DCMAKE_INSTALL_LIBDIR=${_libdir} ..
make

%install
rm -rf $RPM_BUILD_ROOT
cd build
make install DESTDIR=$RPM_BUILD_ROOT

%post -p /sbin/ldconfig
%postun -p /sbin/ldconfig

%clean
rm -rf $RPM_BUILD_ROOT

%files
%{_libdir}/libxil.so
%{_libdir}/pkgconfig/libxil.pc

%files devel
%{_includedir}/xilinx/*

%changelog
* Fri Mar 17 2017 Steffen Vogel <post@steffenvogel.de
- Initial RPM release
