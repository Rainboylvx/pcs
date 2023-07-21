# progress=50
# bar=$(printf "%-${progress}s" "=")
# printf "$bar"
progress=50
bar=$(printf "%-50s" "=")
printf "$bar"
echo
printf "=%.0s" {1..10}
