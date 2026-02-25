data = {"a":1,"b":2}
for k in data.keys():
    if k=="a":
        data["c"] = 3
print(len(data))