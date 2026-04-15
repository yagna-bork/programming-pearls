import subprocess

num_bytes = 20
min_num = -(2 ** num_bytes - 1)
max_missing = min_num

for i in range(100):
    subprocess.run(["./gen_random_ints.o", "ints.txt"])
    missing = int(subprocess.check_output(["./missing_number.o", "ints.txt"]))
    print(missing)
    max_missing = missing if missing > max_missing else max_missing
print ("max diff =", max_missing - min_num)
