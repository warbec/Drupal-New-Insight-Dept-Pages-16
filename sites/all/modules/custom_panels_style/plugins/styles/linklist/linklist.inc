<?php

/**
 * @file
 * Definition of the linklist panel style.
 */
// Plugin definition
$plugin = array(
    'title' => t('Link Lists'),
    'description' => t('Show panel panes in linklist'),
    'render region' => 'panels_linklist_style_render_region',
    'render pane' => 'panels_linklist_style_render_pane',
    'hook theme' => array(
        'panels_linklist_style' => array(
             'variables' => array(
              'content' => NULL,
            ),
            'path' => drupal_get_path('module', 'custom_panels_style') . '/plugins/styles/linklist',
            'template' => 'linklist-style',
        ),
    ),
);

function theme_panels_linklist_style_render_region($vars) {
    foreach ($vars['panes'] as $pane_id => $pane_output) {
        $output .= $pane_output;
    }
    if (empty($output)) {
        return;
    }
   return $output = theme('panels_linklist_style', array('content' => $output));
}


/**
 * Render callback for a single pane.
 */
function theme_panels_linklist_style_render_pane($vars) {
    $content = $vars['content'];
    if (empty($content->content)) {
        return;
    } else {
        $content = $vars['content'];
    }
    $content = theme('panels_pane', array('content' => $content));
    $output = theme('panels_linklist_style', array('content' => $content));
    return $output;
}
