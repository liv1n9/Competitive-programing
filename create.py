import os
from shutil import copyfile

if __name__ == "__main__":
    directory = os.path.dirname(os.path.realpath(__file__)) + "/"
    template_dir = directory + "template.cpp"
    site = ["codeforces", "codechef", "codejam", "hackerrank", "hackerearth"]
    print(site)

    i = 0
    while True:
        try:
            i = int(input("site: "))
            if i in range(len(site)):
                break
        except ValueError:
            pass
    site_dir = directory + site[i] + "/"
    if not os.path.exists(site_dir):
        os.makedirs(site_dir)

    contest = input("contest: ")
    contest_dir = site_dir + contest + "/"
    if not os.path.exists(contest_dir):
        os.makedirs(contest_dir)
    problem = 8
    while True:
        try:
            problem = input("problem: ")
            if problem == "0":
                break
            problem_dir = contest_dir + contest + problem + ".cpp"
            copyfile(template_dir, problem_dir)
        except ValueError:
            pass

    print("done!")