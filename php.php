<?php 

/*
Theme Name: 
Theme URI: http://abscreation.com
Author: habibur rahman
Author URI: http://abscreation.com
Description: 
Version: 1.0
Tags: 
*/

/*this is for custom-field */
<?php echo get_post_meta($post->ID, '',true)?>
/* Registering Wordpress Menu */

add_action('init', 'wpj_register_menu');
function wpj_register_menu() {
	if (function_exists('register_nav_menu')) {
		register_nav_menu( 'wpj-main-menu', __( 'Main Menu', 'brightpage' ) );
	}
}


http://stackoverflow.com/questions/11588539/wordpress-mysql-delete-all-custom-post-type



if endif
========================================================
<?php if ( ! dynamic_sidebar( 'sidebar-top' ) ) : ?>
 <?php endif; ?>



Adding Latest jQuery from Wordpress
========================================================
  /* Adding Latest jQuery from Wordpress */
function abs_latest_jquery() {
	wp_enqueue_script('jquery');
}
add_action('init', 'abs_latest_jquery');
 
 
 
/*====================== dynamic header for theme forest submit*/
<meta charset="<?php bloginfo( 'charset' ); ?>">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<link rel="profile" href="http://gmpg.org/xfn/11" />
		<link rel="pingback" href="<?php bloginfo( 'pingback_url' ); ?>" />




/*===========================include header but write in function.php and this code is for perfect theme forest theme development=================================================*/
<?php 


function various_theme_jquery() {
	wp_enqueue_script('jquery');
}
add_action('init', 'various_theme_jquery');

// this is for language attribute
<?php language_attributes(); ?>
// dynamic  title in wordpress
 <title><?php wp_title('-', true, 'right'); bloginfo( 'name' ); ?></title>
// this is for active thefile

function various_theme_files() {
	global $wp_styles;
	
	/*
	 * Adds JavaScript to pages with the comment form to support
	 * sites with threaded comments (when in use).
	 */
	if ( is_singular() && comments_open() && get_option( 'thread_comments' ) )
		wp_enqueue_script( 'comment-reply' );	
		
	
	/* Registering Styles */
	
	wp_register_style( 'bootstrap', get_template_directory_uri() . '/css/bootstrap.min.css', array(), '1', 'all' );
	wp_register_style( 'bootstrap-theme', get_template_directory_uri() . '/css/bootstrap-theme.min.css', array(), '1', 'all' );
	wp_register_style( 'prettyphoto', get_template_directory_uri() . '/css/prettyPhoto.min.css', array(), '1', 'all' );
	wp_register_style( 'responsive', get_template_directory_uri() . '/responsive.css', array(), '1', 'all' );
	
	
	
	
	
	/* Enqueue Styles */
	
	wp_enqueue_style( 'bootstrap', get_stylesheet_uri(), array(), '1', 'all' );
	wp_enqueue_style( 'bootstrap-theme', get_stylesheet_uri(), array(), '1', 'all' );
	wp_enqueue_style( 'prettyphoto', get_stylesheet_uri(), array(), '1', 'all' );
	wp_enqueue_style( 'responsive', get_stylesheet_uri(), array(), '1', 'all' );
	
	
		
		
	// Loads our main stylesheet.
	wp_enqueue_style( 'various-main-style', get_stylesheet_uri() );
	
	
	
	
	// Loads all javascript files
	
	// Masonry
	wp_enqueue_script( 'jquery-masonry', array( 'jquery' ) );
	
	// Mixit Up
	wp_enqueue_script('v-mixitup', get_template_directory_uri() . '/js/jquery.mixitup.min.js',array('jquery'),'1.0',true);	
	
	// PrettyPhoto
	wp_enqueue_script('v-prettyphoto', get_template_directory_uri() . '/js/jquery.prettyPhoto.min.js',array('jquery'),'1.0',true);	
	
	// Flickr Feed
	wp_enqueue_script('v-jflickrfeed', get_template_directory_uri() . '/js/jflickrfeed.min.js',array('jquery'),'1.0',true);	
	
	// J Dribble
	wp_enqueue_script('v-jribbble', get_template_directory_uri() . '/js/jquery.jribbble-1.0.1.min.js',array('jquery'),'1.0',true);	
	
	// Bootstrap
	wp_enqueue_script('v-bootstrap', get_template_directory_uri() . '/js/bootstrap.min.js',array('jquery'),'1.0',true);	
	
	// Main JS
	wp_enqueue_script('v-main', get_template_directory_uri() . '/js/main.js',array('jquery'),'1.0',true);	
	
	
}
add_action('wp_enqueue_scripts', 'various_theme_files');


?>

/************************=============wp pagenavi======*******//////

<?php if(function_exists('wp_pagenavi')): ?>


	<?php wp_pagenavi(); ?>
	
	
	
header.php
========================================================
<?php echo get_template_directory_uri(); ?>/   <!-- for dynamic theme directory -->
<?php bloginfo( 'template_url' ); ?>   <!-- for dynamic theme directory -->

<?php bloginfo('stylesheet_url'); ?>	<!-- for dynamic stylesheet -->

<?php bloginfo( 'home' ); ?>	<!-- for home page linking -->

<?php bloginfo('name'); ?>	<!-- for blog name -->

<?php echo get_avatar( get_the_author_meta('ID'), 50 ); ?> <!-- for author avatar-->

<?php the_author_posts_link(); ?>  <!-- for author name + link -->

<?php the_time('M d, Y') ?> 	<!-- for post time -->

<title><?php bloginfo('name'); ?><?php wp_title(); ?></title>  <!-- for title -->

<?php echo mysql2date('g:i a - l F j, Y',current_time('timestamp')); ?>		<!-- for clock -->


search.php
========================================================
	<?php if ( have_posts() ) : ?>
				<h1 class="search-page-title"><?php printf( __( 'Search Results for: %s' ), '<span>' . get_search_query() . '</span>' ); ?></h1>
				<?php
				 get_template_part( 'post-loop', 'search' );
				?>
<?php else : ?>
				<div id="post-0" class="post no-results not-found">
					<h2 class="entry-title"><?php echo __( 'Nothing Found' ); ?></h2>
					<div class="entry-content">
						<p><?php echo __( 'Sorry, but nothing matched your search criteria. Please try again with some different keywords.' ); ?></p>
						
					<a id="submit" href="<?php bloginfo( 'home' ); ?>">Home</a>
					</div><!-- .entry-content -->
				</div><!-- #post-0 -->
<?php endif; ?>









All Post Info
========================================================
<?php the_author_posts_link(); ?> <!-- for Post Author -->

<?php the_time('M d, Y') ?>   <!-- for posted time -->

<?php the_category(', '); ?>  <!-- for post category -->

<?php comments_popup_link('No Comment', '1 Comment', '% Comments'); ?>   <!-- for the number of comment & comment link -->

<a href="<?php the_permalink(); ?>" title="<?php the_title(); ?>"><?php _e('Read More..', ''); ?></a>   <!-- for Read More.. option -->




For Header Script 
========================================================
<?php wp_head (); ?>	<!-- this code before </head> --> 

<?php wp_footer (); ?> <!-- this code before </body>  --> 





For Dynamic Menu 
========================================================
<!-- for dynamic menu copy and past in header.php -->
<?php wp_nav_menu( array( 'theme_location' => 'main-menu') ); ?>
<!-- for responsive menu dynamic in header.php -->
<?php wp_nav_menu( array('theme_location' => 'main-menu', 'menu_id' => 'nav', '' => 'default_menu') ); ?>

<!-- for dynamic manu copy ang past in functions.php-->
function wp_register_menu() {

    if (function_exists('register_nav_menu')) {

        register_nav_menu( 'main-menu', __( 'Main Menu') );
    }
}
add_action('init', 'wp_register_menu');	








index.php
========================================================
<?php get_header(); ?>		<!-- for header.php file calling -->

<?php get_footer(); ?>		 <!-- for footer.php file calling -->

<?php get_sidebar(); ?>  	<!-- for sidebar.php file calling -->

<?php get_template_part('file_name'); ?>	 <!-- for any file calling (file_neme.php only "file_neme" no ".php")-->


archive.php
========================================================
						<h1 class="archivetitle">

						<?php if (have_posts()) : ?>

							<?php $post = $posts[0]; // Hack. Set $post so that the_date() works. ?>

								<?php /* If this is a category archive */ if (is_category()) { ?>

									<?php _e('Archive for the'); ?> '<?php echo single_cat_title(); ?>' <?php _e('Category'); ?>                                    

								<?php /* If this is a tag archive */  } elseif( is_tag() ) { ?>

									<?php _e('Archive for the'); ?> <?php single_tag_title(); ?> Tag

								<?php /* If this is a daily archive */ } elseif (is_day()) { ?>

									<?php _e('Archive for'); ?> <?php the_time('F jS, Y'); ?>                                        

								<?php /* If this is a monthly archive */ } elseif (is_month()) { ?>

									<?php _e('Archive for'); ?> <?php the_time('F, Y'); ?>                                    

								<?php /* If this is a yearly archive */ } elseif (is_year()) { ?>

									<?php _e('Archive for'); ?> <?php the_time('Y'); ?>                                        

								<?php /* If this is a search */ } elseif (is_search()) { ?>

									<?php _e('Search Results'); ?>                            

								<?php /* If this is an author archive */ } elseif (is_author()) { ?>

									<?php _e('Author Archive'); ?>                                        

								<?php /* If this is a paged archive */ } elseif (isset($_GET['paged']) && !empty($_GET['paged'])) { ?>

									<?php _e('Blog Archives'); ?>                                        

						<?php } ?>

					</h1>

					<?php get_template_part('post-loop'); ?>
					<?php else : ?>

						<h3><?php _e('404 Error&#58; Not Found'); ?></h3>

					<?php endif; ?>
					
					



For Numbering Pagination
========================================================
<!-- copy and past in functions.php for numbering pagination -->

function pagination($pages = '', $range = 4)
    {  
         $showitems = ($range * 2)+1;  

         global $paged;
         if(empty($paged)) $paged = 1;

         if($pages == '')
         {
             global $wp_query;
             $pages = $wp_query->max_num_pages;
             if(!$pages)
             {
                 $pages = 1;
             }
         }   

         if(1 != $pages)
         {
             echo "<div class=\"pagination\"><span>Page ".$paged." of ".$pages."</span>";
             if($paged > 2 && $paged > $range+1 && $showitems < $pages) echo "<a href='".get_pagenum_link(1)."'>&laquo; First</a>";
             if($paged > 1 && $showitems < $pages) echo "<a href='".get_pagenum_link($paged - 1)."'>&lsaquo; Previous</a>";

             for ($i=1; $i <= $pages; $i++)
             {
                 if (1 != $pages &&( !($i >= $paged+$range+1 || $i <= $paged-$range-1) || $pages <= $showitems ))
                 {
                     echo ($paged == $i)? "<span class=\"current\">".$i."</span>":"<a href='".get_pagenum_link($i)."' class=\"inactive\">".$i."</a>";
                 }
             }

             if ($paged < $pages && $showitems < $pages) echo "<a href=\"".get_pagenum_link($paged + 1)."\">Next &rsaquo;</a>";  
             if ($paged < $pages-1 &&  $paged+$range-1 < $pages && $showitems < $pages) echo "<a href='".get_pagenum_link($pages)."'>Last &raquo;</a>";
             echo "</div>\n";
         }
    } 
	
	
<!-- Use this code and post in loop.php -->
<?php if (function_exists("pagination")) {
        pagination($additional_loop->max_num_pages);
    } ?>

	
<!-- Copy and past in style.css for numbering pagination styling -->

.pagination{clear:both;font-size:11px;line-height:13px;}
.pagination span, .pagination a{display:block;float:left;margin:2px 2px 2px 0;padding:6px 9px 5px 9px;text-decoration:none;width:auto;color:#fff;background:#555;}
.pagination a:hover{color:#fff;background:#3279BB;}
.pagination .current{padding:6px 9px 5px 9px;background:#3279BB;color:#fff;} 







For Pagination 
========================================================
<!-- copy and past in loot.php for pagination -->
<div class="nav-previous"><?php next_posts_link( __( '<span class="meta-nav">&larr;</span> Older posts') ); ?></div>
<div class="nav-next"><?php previous_posts_link( __( 'Newer posts <span class="meta-nav">&rarr;</span>') ); ?></div>





For Post Query
========================================================
<!-- copy and past in loot.php for post query -->
<?php if(have_posts()) : ?>
<?php while (have_posts()) : the_post(); ?>        

	<div class="single_post">
		<h2><a href="<?php the_permalink(); ?>"><?php the_title(); ?></a></h2>

		<div class="post_content">
			<a href="<?php the_permalink(); ?>"><?php the_post_thumbnail('post-image', array('class' => 'post-thumb')); ?></a>
			<?php echo excerpt('60'); ?>
		</div>
		<div class="post_info">
			Posted In: <?php the_category(', '); ?> | Posted on: <?php the_time('M d, Y') ?> <?php comments_popup_link('No Comment', '1 Comment', '% Comments'); ?>
		</div>


	</div>

<?php endwhile; ?>    
<?php endif; ?>


<!-- copy and past in functions.php for excerpt post -->

function excerpt($num) {

$limit = $num+1;

$excerpt = explode(' ', get_the_excerpt(), $limit);

array_pop($excerpt);

$excerpt = implode(" ",$excerpt)." <a href='" .get_permalink($post->ID) ." ' class='".readmore."'>Read More</a>";

echo $excerpt;

}

<!-- copy and past in functions.php for Post thunmbnails -->
	add_theme_support( 'post-thumbnails', array( 'post' ) ); 
	set_post_thumbnail_size( 200, 200, true ); 
	add_image_size( 'post-image', 600, 200, true ); 




 







Dynamic Slider for Custom Post
========================================================
<!-- copy and past in functions.php for Custom Post -->

add_theme_support( 'post-thumbnails', array( 'post', 'slider') );
add_image_size( 'slider-image', 735, 254, true );

/* Register Custom Post Types********************************************/

	
	function create_post_type() {
		register_post_type( 'slider',
			array(
				'labels' => array(
					'name' => __( 'Slides' ),
					'singular_name' => __( 'Slide' ),
					'add_new' => __( 'Add New' ),
					'add_new_item' => __( 'Add New Slide' ),
					'edit_item' => __( 'Edit Slide' ),
					'new_item' => __( 'New Slide' ),
					'view_item' => __( 'View Slide' ),
					'not_found' => __( 'Sorry, we couldn\'t find the Slide you are looking for.' )
				),
			'public' => true,
			'publicly_queryable' => false,
			'exclude_from_search' => true,
			'show_in_menu' => false,
			'menu_position' => 14,
			'has_archive' => false,
			'hierarchical' => false, 
			'capability_type' => 'page',
			'rewrite' => array( 'slug' => 'slide' ),
			'supports' => array( 'title', 'thumbnail' )
			)
		);
	}
	add_action( 'init', 'create_post_type' );
	


For sidebar registration
========================================================	
<!-- copy and past in functions.php -->
function rubel_widget_areas() {

    register_sidebar( array(

        'name' => __( 'Left Menu', 'rubel' ),

        'id' => 'left_sidebar',

        'before_widget' => '<div class="single_sidebar">',

        'after_widget' => '</div>',

        'before_title' => '<h2>',

        'after_title' => '</h2>',

    ) );

}

add_action('widgets_init', 'rubel_widget_areas');


<!-- copy and past in sidebar Aria for sidebar calling-->

<?php dynamic_sidebar('left_sidebar'); ?>









For 404 page
========================================================
<!-- copy and past in 404.php -->
<div class="not_found">
	<h1>404 not found!</h1>
	<p>Sorry, but the page you are trying to reach is unavailable or does not exist.</p>
	<a id="submit" href="<?php bloginfo( 'home' ); ?>">Home</a>
</div>



For page
========================================================
<!-- copy and past in page.php -->
<?php if(have_posts()) : ?><?php while(have_posts())  : the_post(); ?>

	<h2><?php the_title(); ?></h2>

	<?php the_content(); ?>

<?php endwhile; ?>

<?php else : ?>

	<h3><?php _e('404 Error&#58; Not Found'); ?></h3>

<?php endif; ?>




For single.php
========================================================
<!-- copy and past in single.php -->
<?php if(have_posts()) : ?><?php while(have_posts())  : the_post(); ?>

	<h2><?php the_title(); ?></h2>

	<?php the_content(); ?>

   <?php comments_template( '', true ); ?>  

<?php endwhile; ?>

<?php else : ?>

	<h3><?php _e('404 Error&#58; Not Found'); ?></h3>

<?php endif; ?>



Reply Comment Scripts
========================================================

<!-- copy and past in functions.php -->
function comment_scripts(){

   if ( is_singular() ) wp_enqueue_script( 'comment-reply' );

}

add_action( 'wp_enqueue_scripts', 'comment_scripts' );


<!-- copy and past in comments.css From E/All source/comments.css -->



for
========================================================



=====================================================================================================
// Register Custom Taxonomy
=====================================================================================================
<?php
function pages_taxonomy() {
	register_taxonomy(
		'pages_cat',  //The name of the taxonomy. Name should be in slug form (must not contain capital letters or spaces).
		'page',   		 //post type name
		array(
			'hierarchical' 		=> true,
			'label' 			=> 'Page Category',  //Display name
			'query_var' 		=> true,
			'rewrite'			=> array(
				'slug' 			=> 'page-category', // This controls the base slug that will display before each term
				'with_front' 	=> false // Don't display the category base before
				)
			)
	);
}
add_action( 'init', 'pages_taxonomy');		
<?	

=====================================================================================================
// Custom Taxonomy Query
=====================================================================================================

<?php
global $post;
$args = array( 'posts_per_page' => -1, 'post_type'=> 'staff', 'department_cat' => 'Commerical' );
$myposts = get_posts( $args );
foreach( $myposts as $post ) : setup_postdata($post); ?>
				
	// Your Post Content. Title, detail etc. 
	<h2><a href="<?php the_permalink(); ?>"><?php the_title(); ?></a></h2>
					<?php the_content(); ?>
				
<?php endforeach; ?>


========================================================
This code for conditional widget
========================================================


			
<?php if ( ! dynamic_sidebar( 'your_id' ) ) : ?>

// past your default code //
 <?php endif; ?>
			
	
	
	
	
	
========================================================
This code for query in cat
========================================================	
	
<?php

global $post;
$args = array( 'posts_per_page' => 1, 'post_type'=> 'post', 'cat' => 15);
$myposts = get_posts( $args );
foreach( $myposts as $post ) : setup_postdata($post); ?>

// past your post query code //
							
<?php endforeach; ?>


// this is for dynamic menu write in function.php

add_action('init', 'various_nav_menus');
function various_nav_menus() {
	if (function_exists('register_nav_menu')) {
		register_nav_menu( 'main-menu', __( 'Main Menu', 'brightpage' ) );
	}
}

function various_default_nav() {
	echo '<ul class="nav navbar-nav">';
	if ('page' != get_option('show_on_front')) {
		echo '<li><a href="'. home_url() . '/">Home</a></li>';
	}
	wp_list_pages('title_li=');
	echo '</ul>';
}

// this is for dynamenu write in header.php
	<?php
	if (function_exists('wp_nav_menu')) {
		wp_nav_menu(array('theme_location' => 'main-menu', 'menu_class' => 'nav navbar-nav', 'fallback_cb' => 'various_default_nav'));
	}
	else {
		various_default_nav();
	}
	?>			

// this is for shortcode

//////////*****************this code for shortcode*****************//////////////////

					function category_post_shortcode($atts){
						extract( shortcode_atts( array(
							'title' => '',
							'link' => '',
							'category' => '',
						), $atts, 'category_post' ) );
						
						$q = new WP_Query(
							array( 'category' => $category, 'posts_per_page' => '3', 'post_type' => 'post')
							);
					$list = '<div class="latest_from_category"><h2 class="latest_frm_cat_title">'.$title.'</h2> <a href="'.$link.'" class="latest_more_link">more</a>';

					while($q->have_posts()) : $q->the_post();
						//get the ID of your post in the loop
						$id = get_the_ID();

						$post_excerpt = get_post_meta($id, 'post_excerpt', true);  
						$post_thumbnail= get_the_post_thumbnail( $post->ID, 'post-thumbnail' );        
						$list .= '
						
											<div class="single_cate_post floatleft">
												'.$post_thumbnail.'
												<h3>'.get_the_title().'</h3> 
												<p>'.$post_excerpt.'</p>
												<a href="'.get_permalink().'" class="readmore">Read More</a>
											</div>		
						';        
					endwhile;
					$list.= '</div>';
					wp_reset_query();
					return $list;
					}
					add_shortcode('category_post', 'category_post_shortcode');	

/****************************active theme option*****************////////
/* This code for theme options */

add_filter( 'ot_show_pages', '__return_false' );
add_filter( 'ot_show_new_layout', '__return_false' );
add_filter( 'ot_theme_mode', '__return_true' );
include_once( 'option-tree/ot-loader.php' );
include_once( 'includes/theme-options.php' );


// this is for meta box

// add_filter( 'ot_show_pages', '__return_false' );
add_filter( 'ot_show_new_layout', '__return_false' );
add_filter( 'ot_theme_mode', '__return_true' );


include_once( 'option-tree/ot-loader.php' );
include_once( 'inc/theme-options.php' );
include_once( 'inc/meta-boxes.php' );


					
// if i don't wnaan show a category of a post in home page i can use this query in function php file					
					
		function exclude_category_home( $query ) {
if ( $query->is_home ) {
$query->set( 'cat', '-5, -34' );
}
return $query;
}

add_filter( 'pre_get_posts', 'exclude_category_home' );			
					
					
	////////////////////*************this is for image src function use for get the feature images****************///////////////////////				
					<?php 
									$full_image_url = wp_get_attachment_image_src( get_post_thumbnail_id( $post->ID ), 'portfolio-big' );
								?>

								// when i will use it i have to use 
								<?php echo $full_image_url[0] ;?>

		// shortcode custpost// this is custom post for prising table;
		
	function create_post_type() {
		register_post_type( 'pricing',
					array(
						'labels' => array(
								'name' => __( 'pricing table' ),
								'singular_name' => __( 'pricing' ),
								'add_new' => __( 'Add New' )
								
						),
					'public' => true,
					'has_archive' => true,
					'rewrite' => array( 'slug' => 'pricing' ),
					'supports' => array( 'title', 'editor', 'custom-fields','page-attributes','thumbnail' )
					)
				);	

}
add_action( 'init', 'create_post_type' );


///////////////////****************upload your logo by using option tree**************///////////////////////////////
					<?php 
						$logo=get_option_tree( 'logo_upload', '', false);
					?>
					
					<?php if ( function_exists( 'ot_get_option' ) ) : ?>
					<a class="navbar-brand logo-nav" href="<?php echo site_url();?>"><img src="<?php echo $logo ;?>" /></a>
					<?php else :?>
							// your defoult id
					<?php endif; ?>
	//////////////////***************** OR**********////////////////				
					
					
					<?php if ( function_exists( 'get_option_tree') ) : if( get_option_tree( 'left_logo') ) : ?>    
						<a href="<?php bloginfo('home'); ?>"><img src="<?php get_option_tree( 'left_logo', '', 'true' ); ?>" alt=""/></a>
					<?php else : ?>
						<img src="<?php echo get_template_directory_uri(); ?>/img/logo.png"/>
					<?php endif; endif; ?> 









			
					

?>