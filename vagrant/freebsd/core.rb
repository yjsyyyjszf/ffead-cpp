
def provider_libvirt(config)
  config.vm.provider :libvirt do |virt, override|
    override.vm.box = "freebsd/FreeBSD-12.0-RELEASE"

    virt.graphics_type = "none"
    virt.memory = "2048"
    virt.cpus = "2"

  end
end

def provider_virtualbox(config)
  config.vm.provider :virtualbox do |vb, override|
    override.vm.box = "freebsd/FreeBSD-12.0-RELEASE"

    vb.gui = false
    vb.customize ["modifyvm", :id, "--natdnshostresolver1", "on"]
    vb.customize ["modifyvm", :id, "--natdnsproxy1", "on"]
    vb.memory = "2048"
    vb.cpus = "2"

  end
end
