file(REMOVE_RECURSE
  "doxygen/output"
  "../../doc/html"
  "sphinx/_doctrees"
  "sphinx/_build"
  "CMakeFiles/change_section_title_install"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/change_section_title_install.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
