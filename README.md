# DPP documentation template

This is a template for the *Design for Physical Prototyping* project documentation. 
It is a modified version of the *bare-minimum* [Jekyll] template [Just the Docs].
It can be built and published on [GitHub Pages]. This repository will look like [this](https://pretoms.github.io/dpp_docs_template/) when built.

**To get started with creating a site, clone this repository by clicking "[use this template]"!**

After completing the creation of your new site on GitHub, update it as needed:

## Replace the content of the template pages

Update the following files to your own content:

- `my_project/my_project.md` rename project folder and main file to your specific project name
- `README.md` (information for those who access your site repo on GitHub: replace it with your text or just delete content and leave it empty)

Put all images, videos and GIFs you want to embed in your documentation into the assets folder.

## Get familiar with Markdown & Just the Docs

Markdown is a lightweight markup language for creating formatted text using a plain-text editor.
[Here](https://commonmark.org/help/) you can find a reference and a tutorial for getting started.

For Just the Docs specific information reference the [documentation page](https://just-the-docs.github.io/just-the-docs/). 

## Publishing your site on GitHub Pages

1.  If your created site is `YOUR-GITHUB-USERNAME/YOUR-REPO-NAME`, update `_config.yml` to:

    ```yaml
    title: YOUR TITLE
    description: YOUR DESCRIPTION
    theme: just-the-docs

    url: https://YOUR-GITHUB-USERNAME.github.io/YOUR-REPO-NAME

    aux_links: # remove if you don't want this link to appear on your pages
      Template Repository: https://github.com/YOUR-GITHUB-USERNAME/YOUR-REPO-NAME
    ```

2.  Push your updated `_config.yml` to your site on GitHub.

3.  In your newly created repo on GitHub:
    - go to the `Settings` tab -> `Pages` -> `Build and deployment`, then select `Source`: `GitHub Actions`.
    - if there were any failed Actions, go to the `Actions` tab and click on `Re-run jobs`.

----

[^1]: [It can take up to 10 minutes for changes to your site to publish after you push the changes to GitHub](https://docs.github.com/en/pages/setting-up-a-github-pages-site-with-jekyll/creating-a-github-pages-site-with-jekyll#creating-your-site).

[Jekyll]: https://jekyllrb.com
[Just the Docs]: https://github.com/just-the-docs/just-the-docs-template
[GitHub Pages]: https://docs.github.com/en/pages
[use this template]: https://github.com/pretoms/dpp_docs_template/generate
