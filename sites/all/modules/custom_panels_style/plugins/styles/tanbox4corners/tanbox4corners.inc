<?php

/**
 * @file
 * Definition of the tanbox4corners panel style.
 */
// Plugin definition
$plugin = array(
    'title' => t('Tan Box With All 4 Corners Rounded'),
    'description' => t('Show panel panes in tanbox4corners'),
    'render region' => 'panels_tanbox4corners_style_render_region',
    'render pane' => 'panels_tanbox4corners_style_render_pane',
    'hook theme' => array(
        'panels_tanbox4corners_style' => array(
             'variables' => array(
              'content' => NULL,
            ),
            'path' => drupal_get_path('module', 'custom_panels_style') . '/plugins/styles/tanbox4corners',
            'template' => 'tanbox4corners-style',
        ),
    ),
);

function theme_panels_tanbox4corners_style_render_region($vars) {
    foreach ($vars['panes'] as $pane_id => $pane_output) {
        $output .= $pane_output;
    }
    if (empty($output)) {
        return;
    }
   return $output = theme('panels_tanbox4corners_style', array('content' => $output));
}


/**
 * Render callback for a single pane.
 */
function theme_panels_tanbox4corners_style_render_pane($vars) {
    $content = $vars['content'];
    if (empty($content->content)) {
        return;
    } else {
        $content = $vars['content'];
    }
    $content = theme('panels_pane', array('content' => $content));
    $output = theme('panels_tanbox4corners_style', array('content' => $content));
    return $output;
}
