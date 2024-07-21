nums = list(map(int, input().split()))
case_num = 1
while nums[0]:
    print(f"Case {case_num}: ", end='')
    case_num += 1
    if nums[0] % 2:
        print(nums[(nums[0]+1) // 2]/1)
    else:
        print((nums[nums[0]//2] + nums[nums[0]//2+1]) / 2)
    nums = list(map(int, input().split()))