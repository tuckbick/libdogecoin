{
  "targets": [
    {
      "target_name": "dogecoinjs",
      "sources": ["dogecoinjs.c"],
      "libraries": [
        "<(module_root_dir)/../../.libs/libdogecoin.a"
      ],
      "include_dirs": ["<(module_root_dir>/../../../include"],
    }
  ]
}
