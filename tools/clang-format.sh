#!/bin/bash

# clang-format is not friendly for xunit cut.
for f in `find . -type f -regex '.*\.\(c\|cc\|h\|\)$'`; do 
  if [[ "$f" =~ .*_test\.cc ]]; then
    echo "should not format $f"
  else
    clang-format -i $f
  fi
done
