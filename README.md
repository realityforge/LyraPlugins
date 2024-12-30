# Lyra Plugins

This repository just contains a copy of the Lyra Plugins sourced from the `Samples/Games/Lyra/Plugins` directory in the https://github.com/EpicGames/UnrealEngine repository.
The intent is that this repository makes it easy to braid in specific versions of the plugins into downstream projects.

The plugins are mostly unmodified from the original Lyra plugins. To see the differences between the plugins as provided by this repository and the original plugins provided by Lyra you can run the command:

```bash
git fetch
git diff origin/main origin/upstream
```

Minor modifications exist where they have been deemed desirable or when they are awaiting reintegration into the Lyra sample.

### Braiding in a Plugin

Plugins can be added to a project using [Braid](https://cristibalan.github.io/braid/).

An example of braiding in a single plugin "ModularGameplayActors":
```sh
$ braid add --path Plugins/ModularGameplayActors https://github.com/realityforge/LyraPlugins.git Plugins/ModularGameplayActors
Braid: Adding mirror of 'https://github.com/realityforge/LyraPlugins.git' branch 'main'.
Braid: Added mirror at '6728c9e'.
```

### Updating to new releases of Unreal Engine

The plugins can be upgraded by using commands similar to the following:

```bash
# Switch to the latest upstream branch
git checkout upstream
git pull

# Checkout latest Unreal Engine release
rm UnrealEngine
git clone --depth 1 --single-branch --branch=release  https://github.com/EpicGames/UnrealEngine.git

# Move released plugins into expected location
rm -rf Plugins
mv UnrealEngine/Samples/Games/Lyra/Plugins Plugins

# Remove Example specific plugins
rm -rf Plugins/GameFeatures/ Plugins/LyraExtTool/ Plugins/LyraExampleContent/

# Commit changes
git add Plugins
git commit -m "Import 5.5.1 release "
git tag upstream_5.5.1-release
git push
git push --tags

# Merge upstream changes into local branch
git checkout main
git pull
git merge upstream
git tag 5.5.1-release
git push
git push --tags
```
