PROJECT_CEEDLING_ROOT = "vendor/ceedling"

load "#{PROJECT_CEEDLING_ROOT}/lib/ceedling.rb"

Ceedling.load_project
ENV['GCOV_BUILD_PATH'] = "test_output/gcov"

task :default => %w[ test:all release ]
