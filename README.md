# simple_shell
## How to be a Collaborator in GitHub

We made this guide for us. 
Chapter Shell Project at Holberton School.

### Creating collaborators

Match type example

| User 1 | User 2 
| :------- | ------: 
| - Create Repository (go to `Settings`, select `Collaborators` and write mail or collaborator user)| Accept invitation
| - Be sure to make it public | Clone Repo  (set user and pass)
| Ready!

### Save changes 

Changes in master branch

| User 1 | User 2 
| :------- | ------: 
| file `f1`| Change some things `f1` and push origin master
| git pull origin master  | Ready!

### Branchs

Changes in another branch

| User 1 | User 2 
| :------- | ------: 
| - Create a new branch `toconfirm` with: `git checkout -b toconfirm` where `-b` is if it does not exist, create (Create info from origin master)| In `toconfirm` (the new branch) change a file and push with: `git push origin toconfirm`
| All times both users must fetch for download all the changes: `git fetch`. `git branch -v` is name of current branch.
 | When branch changes work, should merge: we prefer go to github.com/project_name, manual branch change, create Pull Request, Merge this PR
| Ready!

Note that sometimes `git fetch` doesn't work to download the changes of all our branches, we must move to the branch and do `git pull origin name_branch`.

Git will tell us that we have pending PR's in `HEAD`

Always Ask Why
----
#AAW
