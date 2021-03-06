# -*- encoding: utf-8 -*-
# stub: ceedling 0.18.0 ruby lib vendor/cmock/lib

Gem::Specification.new do |s|
  s.name = "ceedling"
  s.version = "0.18.0"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.require_paths = ["lib", "vendor/cmock/lib"]
  s.authors = ["Mike Karlesky, Mark VanderVoord", "Greg Williams", "Matt Fletcher"]
  s.date = "2015-03-12"
  s.description = "Ceedling provides a set of tools to deploy its guts in a folder or which can be required in a Rakefile"
  s.email = ["michael@karlesky.net, mvandervoord@gmail.com, williams@atomicobject.com, fletcher@atomicobject.com"]
  s.executables = ["ceedling"]
  s.files = ["bin/ceedling"]
  s.homepage = "http://throwtheswitch.org/"
  s.licenses = ["MIT"]
  s.rubygems_version = "2.2.2"
  s.summary = "Ceedling is a set of tools for the automation of builds and test running for C"

  s.installed_by_version = "2.2.2" if s.respond_to? :installed_by_version

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_runtime_dependency(%q<thor>, [">= 0.14.5"])
      s.add_runtime_dependency(%q<rake>, [">= 0.8.7"])
    else
      s.add_dependency(%q<thor>, [">= 0.14.5"])
      s.add_dependency(%q<rake>, [">= 0.8.7"])
    end
  else
    s.add_dependency(%q<thor>, [">= 0.14.5"])
    s.add_dependency(%q<rake>, [">= 0.8.7"])
  end
end
